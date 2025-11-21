#include <bits/stdc++.h>
using namespace std;
int islandPerimeter(vector<vector<int>> &grid)
{
    int ans = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                while (!q.empty())
                {
                    auto z = q.front();
                    q.pop();
                    if (z.first < 0 || z.first > grid.size() - 1 ||
                        z.second < 0 || (z.second > grid[0].size() - 1))
                        ans++;
                    else if (grid[z.first][z.second] == 0)
                        ans++;
                    else if (vis[z.first][z.second])
                        continue;
                    else if (grid[z.first][z.second] == 1)
                    {
                        vis[z.first][z.second] = true;
                        
                            q.push({z.first - 1, z.second});
                        
                            q.push({z.first + 1, z.second});
                       
                            q.push({z.first, z.second - 1});
                        
                            q.push({z.first, z.second + 1});
                    }
                    
                    
                }
                return ans;
            }
        }
    }
    return 0;
}
bool canPartition(vector<int> &nums)
{
    long long sum = 0;
    for (auto n : nums)
        sum += n;
    if (sum & 1)
        return false;
    long long target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = target; nums[i - 1] <= target && j >= nums[i - 1]; j--)
        {
            dp[j] = dp[j - nums[i - 1]] || dp[j];
        }
    }
    return dp[target];
}
void Solve()
{
    vector<vector<int>> a{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    vector<int> b{4, 5, 6};
    cout << islandPerimeter(a);
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}