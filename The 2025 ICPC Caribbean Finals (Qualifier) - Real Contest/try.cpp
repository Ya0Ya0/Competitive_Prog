#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive DFS function to find articulation points
void findAPs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &isAP, vector<vector<int>> &adj, int &time)
{
    int children = 0;
    disc[u] = low[u] = ++time;

    for (int v : adj[u])
    {
        if (disc[v] == -1)
        { // If v is not visited yet
            children++;
            parent[v] = u;
            findAPs(v, disc, low, parent, isAP, adj, time);

            // After the DFS call for v returns, update low-link value of u
            low[u] = min(low[u], low[v]);

            // --- Articulation Point Conditions ---
            // 1. u is the root of the DFS tree and has more than one child.
            if (parent[u] == -1 && children > 1)
            {
                isAP[u] = true;
            }

            // 2. u is not the root, and the low-link value of its child v
            //    is greater than or equal to the discovery time of u.
            if (parent[u] != -1 && low[v] >= disc[u])
            {
                isAP[u] = true;
            }
        }
        else if (v != parent[u])
        { // If v is visited and not the parent, it's a back edge
            // Update low-link value of u using the discovery time of v
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
    int n = 7; // Number of vertices
    vector<vector<int>> adj(n);

    // --- Example Graph ---
    // Represents a network where nodes 0, 1, and 3 are critical.
    //
    //    1 2
    adj[1].push_back(2);
    adj[2].push_back(1);
    // 2 3
    adj[2].push_back(3);
    adj[3].push_back(2);
    // 1 3
    adj[1].push_back(3);
    adj[3].push_back(1);
    // 3 4
    adj[3].push_back(4);
    adj[4].push_back(3);
    // 4 5
    adj[4].push_back(5);
    adj[5].push_back(4);
    // 3 5
    adj[3].push_back(5);    
    adj[5].push_back(3);

    // --- Initialization ---
    vector<int> disc(n, -1);     // Discovery times
    vector<int> low(n, -1);      // Low-link values
    vector<int> parent(n, -1);   // Parent in DFS tree
    vector<bool> isAP(n, false); // To store results
    int time = 0;

    cout << "Graph represented by adjacency list:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i << " -> ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // --- Find Articulation Points ---
    // We loop through all vertices in case the graph is disconnected
    for (int i = 0; i < n; ++i)
    {
        if (disc[i] == -1)
        {
            findAPs(i, disc, low, parent, isAP, adj, time);
        }
    }

    // --- Print the result ---
    cout << "\nCritical points (Articulation Points) that cannot be removed:" << endl;
    for (int i = 0; i < n; ++i)
    {
        if (isAP[i])
        {
            cout << i << " ";
        }
    }
    cout << endl; // Expected Output: 1 3 4

    return 0;
}