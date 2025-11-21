#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string s1,s2;cin >>s1 >>s2;
    for(auto c : s1)
        for(auto v : s2)
        {
            if(c > v)
            {
                cout << "YES\n";return;
            }
        }
    cout << "NO\n";
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