#include <bits/stdc++.h>
using namespace std;

bool comparePairs(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
}
int minFallingPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        dp[i] = grid[0][i];
    
    for (int i = 1; i < n; i++)
    {
        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comparePairs)> pq(&comparePairs);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        for (int j = 0; j < n; j++)
        {
            pq.push({dp[j], j});
        }
        for (int j = 0; j < n; j++)
        {
            if (pq.top().second == j)
            {
                auto z = pq.top();
                pq.pop();
                dp[j] = pq.top().first + grid[i][j];
                pq.push(z);
            }
            else
                dp[j] = pq.top().first + grid[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(dp[i], ans);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // int ans = minOperations(grid);
    cout << minFallingPathSum(grid);

    return 0;
}