#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Function to add an edge to the tree
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS function to color the tree and count the number of ways
void dfs(vector<int> adj[], vector<vector<int>>& dp, int node, int parent) {
    // Base case: if the node is a leaf, it can be colored in 3 ways
    dp[node][0] = 1; // Node can be colored R
    dp[node][1] = 1; // Node can be colored G
    dp[node][2] = 1; // Node can be colored B

    // Traverse all children of the node
    for (int child : adj[node]) {
        if (child == parent) continue;

        // Recursively color the child
        dfs(adj, dp, child, node);

        // Update the number of ways to color the current node
        dp[node][0] = (dp[node][0] * ((long long)(dp[child][1] + dp[child][2]) % MOD)) % MOD;
        dp[node][1] = (dp[node][1] * ((long long)(dp[child][0] + dp[child][2]) % MOD)) % MOD;
        dp[node][2] = (dp[node][2] * ((long long)(dp[child][0] + dp[child][1]) % MOD)) % MOD;
    }
}

// Function to count the number of ways to color the tree
int countColoringWays(vector<int> adj[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dfs(adj, dp, 1, -1);

    // The result is the sum of ways to color the root node
    int result = (dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
    return result;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    vector<int> adj[n + 1];
    cout << "Enter the edges of the tree (u v format):" << endl;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int ways = countColoringWays(adj, n);
    cout << "Number of ways to color the tree: " << ways << endl;

    return 0;
}