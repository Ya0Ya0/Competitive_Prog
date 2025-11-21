#include "bits/stdc++.h"
using namespace std;
#define ll long long
// #define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = r * a;
        a = a * a;
        b /= 2;
    }
    return r;
}
void Solve()
{
    ll n, q, r;
    cin >> n >> q >> r;
    vector<vector<ll>> t(n + 1);
    set<ll> pqq;
    map<ll, vector<pair<ll, ll>>> mp;
    vector<vector<ll>> ans2(n+1);
    vector<ll> ans(q + 1);
    vector<pair<ll,ll>> qq(q + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;

        t[a].push_back(b);
        t[b].push_back(a);
    }
    for (ll i = 0; i < q; i++)
    {
        ll qu, th;
        cin >> qu >> th;
        qq[i] = {qu,th};
        mp[qu].push_back({th, i});
    }
    vector<int>z(all(pqq));
    auto dfs = [&](auto self, ll c, ll p) -> void
    {
        pqq.insert(c);

        if (mp.count(c))
        {
            ans2[c] = vector<ll>(all(pqq));
            
        }
        for (auto e : t[c])
        {
            if (e != p)
                self(self, e, c);
        }
        pqq.erase(c);
    };
    dfs(dfs, r, 0);
    for (ll i = 0; i < q ; i++)
    {
        auto [c,th] = qq[i];
        cout << ans2[c][th-1] << "\n";
    }
    
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}