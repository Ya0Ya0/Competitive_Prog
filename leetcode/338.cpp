#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.length()+1,vector<int>(s.length()+1));
        for(int i = 1; i <= t.length(); i++ )
            for(int j = 1; j <= s.length(); j++)
                {
                    if(s[j - 1] == t[i - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = dp[i - 1][j];
                }
        return dp[t.length()][s.length()];
    }
};
void Solve()
{
    vector<int> t{1,2,3};
    cout << Solution::isSubsequence("feo","feitillo");
    // for(auto &A : a)
    //     cout << A;
}

int main ()
{
    int tt = 1; //cin >> tt;
    while(tt--)
    {
        Solve();
    }
}