#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string s; cin >> s;
    string ans;
    for(auto c : s)
    {
        if(ans.empty() || ans.back() != c)
            ans.push_back(c);
    }
    while(ans.length() > 3 )
    {
        ans.pop_back();
        ans.pop_back();
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}