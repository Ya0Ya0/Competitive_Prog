#include <bits/stdc++.h>
using namespace std;

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> dis(n);
        queue<int> q;
        q.push(i);
        vector<bool> vis(n);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (vis[cur])
                continue;
            vis[cur] = true;
            for (auto e : edges[cur])
            {
                if (vis[e])
                    continue;
                q.push(e);
                dis[e] = dis[cur] + 1;
                ans[i] += dis[e];
            }
        }
    }
    return ans;
}

void Solve()
{
    //[[0,1],[0,2],[2,3],[2,4],[2,5]]
    vector<vector<int>> a{{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> b{4, 5, 6};
    for(int i=0;i<6;i++)
    cout << sumOfDistancesInTree(6,a)[i];
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}