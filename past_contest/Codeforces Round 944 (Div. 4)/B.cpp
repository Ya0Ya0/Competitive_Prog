#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string s;cin >> s;
    string b = s.substr(1,s.length()-1) + s[0];
    if(s==b)
        cout << "NO\n";
    else{
        cout << "Yes\n";
        cout <<b << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}