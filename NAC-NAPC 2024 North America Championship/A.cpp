#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
bool sorter(pll *a, pll *b)
{
    return a->second > b->second;
}

void Solve()
{
    int n;
    cin >> n;
    vector<pll> ent(n);
    ll suma = 0, sumb = 0;
    for (auto &e : ent)
    {
        cin >> e.first;
        cin >> e.second;
        suma += e.first;
        sumb += e.second;
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}