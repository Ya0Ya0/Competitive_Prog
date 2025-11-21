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
    int n, e, s;
    cin >> n >> e >> s;
    vector<vector<int>> g(n);
    vector<int> w(s);
    for (auto &e : w)
        cin >> e;
    vector<int> ax(s);
    vector<ll> even, odd, preve(1), prodd(1);
    for (int i = 0; i < s; i++)
    {

        if (w[i] % 2 == 0)
            even.push_back(w[i]);
        else
        {
            odd.push_back(w[i]);
        }
    }
    sort(all(even));
    reverse(even.begin(), even.end());
    sort(all(odd));
    reverse(odd.begin(), odd.end());
    for (int i = 0; i < even.size(); i++)
    {
        preve.push_back(even[i] + preve[i]);
    }
    for (int i = 0; i < odd.size(); i++)
    {
        prodd.push_back(odd[i] + prodd[i]);
    }

    // read(ent,n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector<vector<ll>> dis(n, vector<ll>(2, INT_MAX));
    vector<int> vis(n, 0);
    auto dfs = [&](auto self, int v) -> void
    {
        vis[v] = 1;
        for (auto u : g[v])
        {
            dis[u][0] = min(dis[u][0], dis[v][1] + 1);
            dis[u][1] = min(dis[u][1], dis[v][0] + 1);
            if (!vis[u])
            {
                self(self, u);
            }
        }
    };
    dis[0][0] = 0;
    dfs(dfs, 0);
    for (int i = 0; i < n; i++)
    {
        ll cur = preve.back();

        if ((prodd.size() - 1) & 1)
        {
            cur += prodd[prodd.size() - 2];
        }
        else
        {
            cur += prodd.back();
        }
        ll cur0 = cur;
        cur = preve.back();
        if ((prodd.size() - 1) & 1)
        {
            cur += prodd.back();
        }
        else
        {
            cur += prodd[prodd.size() - 2];
        }

        if ((cur0 >= dis[i][0] && preve.size() > 1) || (prodd.size() > 1 && cur >= dis[i][1]))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n";
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