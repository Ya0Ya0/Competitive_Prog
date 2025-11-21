#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string s;cin >> s;
    long ans = 0,ok = 0;
    for(int i = 0; i < s.length()-1; i++)
    {
        if(s[i] =='0' && s[i+1]=='1')
            ok = 1;
        if(s[i] != s[i+1])
            ans++;
    }
    cout <<ans-ok+1 <<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}