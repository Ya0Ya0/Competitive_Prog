#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
        cin >> e;
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
    ll MOD = 998244353;
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> depth(n + 1);
    vector<ll> s_depth(n + 1);
    vector<ll> s(n + 1);
    depth[1] = 0;
    s_depth[0] = 0;
    for (ll i = 2; i <= n; i++)
    {
        ll p;
        cin >> p;
        depth[i] = depth[p] + 1;
        adj[p].push_back(i);
    }
    ll ans = 0;
    queue<pair<ll, ll>> q;
    q.push({1,1});
    auto bfs = [&](auto self, pair<ll, ll> z) -> void
    {
        q.pop();
        ll v = z.first;
        ll p = z.second;
        if (p == 1)
        {
            s[v] = 1;
            ans++;
            s_depth[depth[v]]++;            
        }
        else
        {
            s[v] = (s_depth[depth[p]] - s[p]+MOD) % MOD;
            ans = (ans + s[v]+MOD) % MOD;
            s_depth[depth[v]] = (s[v] + s_depth[depth[v]]+MOD) % MOD;           
        }
        for (auto u : adj[v])
        {
            q.push({u,v});
        }
    };
    while (!q.empty())
        bfs(bfs, q.front());
    cout << ans%MOD << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}