#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int feo(int a, int &b)
    {
        a++;(b)++;
        return 0;
        string z;z.substr(2,5);
        z.length();
    }
    static int countVowelStrings(int n)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        for (long long i = 0; i < 5; i++)
            dp[1][i] = 5 - i ;
        for (long long i = 2; i <= n; i++)
        {
            for (long long j = 0; j < 5; j++)
            {
                for (long long z = j; z < 5; z++)
                {
                    dp[i][j] += dp[i - 1][z];
                }
            }
        }
        long long ans = dp[n][0];
        
        return ans;
    }
};
void Solve()
{
    //vector<int> t{1, 1, 1, 1};
    //long long a = Solution::countVowelStrings(33);
    int a=0,b=0;
    Solution::feo(a,b);
    cout << a << b;
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}