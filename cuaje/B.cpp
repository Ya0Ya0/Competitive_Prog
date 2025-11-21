#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n; cin >> n;
    string a,b;
    cin >> a >> b;
    vector<int> va(11),vb(11);
    for(int i =0 ;i < n; i++)
    {
        va[a[i]-'0']++;
        vb[b[i]-'0']++;
    }
    if(va[0] == vb[0] && va[1] == vb[1])
    {
        cout<<"YES\n";return;
    }
    cout << "NO\n";return;
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