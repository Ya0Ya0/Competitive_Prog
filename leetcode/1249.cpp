#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string minRemoveToMakeValid(string s) {
        int open = 0;
        
        string ans, ret;
        for (char c : s) {
            if (c == '(') {
                open++;

            } else if (c == ')') {
                open--;
            }
            if (open >= 0) {
                ans.push_back(c);
            } else
                open++;
        }
        if(!open)
            return ans;
        int i = ans.length() - 1;
        while (i>=0) {
            
            if (ans[i] == '(' && open)
                open--;
                
            else {
                ret.push_back(ans[i]);
            }
            i--;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};


void Solve()
{
    vector<int> a{2, 1, 8};
    vector<int> b{4, 5, 6};
    cout << Solution::minRemoveToMakeValid("(a(b(c)d)");
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}