#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int ans = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (vis[i][j])
                continue;
            if (grid[i][j] != '1')
                continue;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            while (!q.empty())
            {
                auto [it, jt] = q.front();
                q.pop();
                if(vis[it][jt])continue;
                vis[it][jt] = true;
                if (it < grid.size() - 1 && grid[it + 1][jt] == '1'&& !vis[it + 1][jt])
                    q.push({it + 1, jt});
                if (jt < grid[0].size() - 1 && grid[it][jt + 1] == '1' && !vis[it][jt + 1])
                    q.push({it, jt + 1});
                if (it > 0 && grid[it - 1][jt] == '1' && !vis[it - 1][jt])
                    q.push({it-1, jt});
                if (jt > 0 && grid[it][jt - 1] == '1' && !vis[it][jt - 1])
                    q.push({it, jt-1});
            }
            ans++;
        }
    }

    return ans;
}
void Solve()
{
    vector<vector<char>> t{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    vector<int> a;
    int z = numIslands(t);
    cout << z;
    for (auto &A : a)
        cout << A;
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}