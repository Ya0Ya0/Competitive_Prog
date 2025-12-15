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
void init() {};
void Solve()
{
    int n;
    cin >> n;
    // read(ent,n);
    vector<vector<int>> g(n + 2);
    for (int i = 1; i < n; i++)
    {
        ll u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y)
        {
            g[u].push_back(v);
        }
        else
        {
            g[v].push_back(u);
        }
    }
    vector<int> ans, vis(n + 2);
    auto dfs = [&](auto self, int nd) -> void
    {
        vis[nd] = 1;
        for (auto e : g[nd])
        {
            if(!vis[e])
            self(self, e);
        }
        ans.push_back(nd);
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(dfs, i);
    }
    reverse(all(ans));
    vector<int> fans(n);
    // iota(all(p),1);
    for (int i = 0; i < n; i++)
    {
        fans[ans[i] - 1] = n - i;
    }
    for (auto e : fans)
    {
        cout << e << " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}