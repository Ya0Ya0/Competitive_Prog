#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,q; cin >> n >> q;
    vector<int>ent(n),queries(q);
    for(auto& e :ent) cin >> e;
    for(auto& que :queries) cin >> que;
    for(auto que : queries)
    {
        cout << min(ent[0]-1,que) << " ";
    }
    cout << "\n";
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