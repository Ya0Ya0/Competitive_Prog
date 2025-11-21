#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    int ans = a*b + b*c;
    cout << ans;
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