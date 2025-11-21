#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,ans = 0;; cin >> n;
    vector<int> ent(n);
    for(auto &e : ent) cin >> e;
    sort(ent.begin(),ent.end());
    for(int i =0; i < n - 1; i++)
    {
        if(ent[i] == ent[i+1])
        {
            ans++;
            i++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}