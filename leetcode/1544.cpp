#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string makeGood(string s) {
        string ans;
        ans += s[0];
        int pos = 1;
        reverse()
        for(int i = 1; i < s.length(); i++)
        {
            if(pos == 0)
            {
               pos++;
                ans += s[i]; 
                continue; 
            }
            int aux = abs(s[i]-ans[pos-1]) == abs('a'-'A') ;
            if(aux)
            {
                pos--;
                ans = ans.substr(0,pos);
            }
            else 
            {
                pos++;
                ans += s[i]; 
            }
        }
        return ans;
    }
};
void Solve()
{
    vector<int> a{2, 1, 8};
    vector<int> b{4, 5, 6};
    cout << Solution::makeGood("abBAcC");
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}