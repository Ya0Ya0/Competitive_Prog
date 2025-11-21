#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,m;
    cin >> n >> m;
    string s1,s2;cin >> s1 >> s2;
    int ite = 0;
    for(auto c : s2)
    {
        if(ite == n)
        {
            break;
        }
        if(c == s1[ite])ite++;
    }
    cout << ite << "\n";
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