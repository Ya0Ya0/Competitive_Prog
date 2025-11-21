#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0;
        vector<int> arr(30);
        int ans = 0;
        for (r = 0; r < s.length(); r++)
        {
            arr[s[r] - 'a']++;
            
            while (arr[s[r] - 'a'] > 1)
            {
                arr[s[l] - 'a']--;                
                l++;                
            }
            
            ans = max(ans,r - l +1  );
        }
        return ans;
    }
};
void Solve()
{
    Solution::lengthOfLongestSubstring("pwwkew");
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}