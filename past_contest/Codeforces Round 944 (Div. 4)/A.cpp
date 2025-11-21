#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int a,b;cin >> a >> b;
    cout << min(a,b) << " " << max(a,b) << "\n";
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