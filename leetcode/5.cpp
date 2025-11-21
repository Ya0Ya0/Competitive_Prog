#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    static string longestPalindrome(string s) {
        char c;
        toupper(c);
        int ans = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            int l = i - 1, r = i + 1, size = 1;
            while (l >= 0 && r < s.length()) {
                if (s[l] == s[r])
                    size += 2;
                else {
                   
                    break;
                }
                l--;
                r++;
            }
            if (size > ans) {
                ans = size;
                start = l + 1;
            }
            if (s[i] == s[i + 1] && i != s.length() - 1) {
                 l = i , r = i + 1, size = 0;
                while (l >= 0 && r < s.length()) {
                    if (s[l] == s[r])
                        size += 2;
                    else {
                        
                        break;
                    }
                    l--;
                    r++;
                }
                if (size > ans) {
                    ans = size;
                    start = l + 1;
                }
            }
        }
        return s.substr(start, ans);
    }
};
void Solve()
{
    string a = "cddb";
    vector<int> b{4, 5, 6};
    cout << Solution::longestPalindrome(a);
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}