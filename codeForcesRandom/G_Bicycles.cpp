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
ll const mod = 998244353;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a + mod) % mod;
        a = (a * a + mod) % mod;
        b /= 2;
    }
    return r;
}
// ll const mod = 998244353;
void Solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<ll>> dis;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        
    }
    read(ent, n);
    pq q;
    for(auto e : ent)
    {
        if (dis.find(e) == dis.end())
        {
            dis[e] = vector<ll>(n, LLONG_MAX);
        }
    }
    dis[ent[0]][0] = 0;
    q.push({0, {0, ent[0]}});
    while (!q.empty())
    {
        auto [c, p] = q.top();
        q.pop();
        ll v = p.first;
        ll s =ent[v];
        ll ss = p.second;
        for (auto &[e, w] : g[v])
        {

            if (c + w*s < dis[s][e])
            {
                dis[s][e] = c + w*s;
                q.push({dis[s][e], {e, s}});
            }
        }
        for (auto &[e, w] : g[v])
        {

            if (c + w*ss < dis[ss][e])
            {
                dis[ss][e] = c + w*ss;
                q.push({dis[ss][e], {e, ss}});
            }
        }
    }

    // vector<ll> dis2(n, LLONG_MAX);
    // dis2[0] = 0;
    // for(int i =0;i <n;i++)
    // {
    //     for(int j =0;j < n;j++)
    //     {
    //         dis2[j] = min(dis2[j], dis2[i]+dis[i][j]*ent[i]);
    //     }

    // }
    // cout << dis2[n - 1] << endl;
    
    ll ans = LONG_LONG_MAX;
    for(auto &[e, v] : dis)
    {
        ans = min(ans, v[n - 1]);
    }
    cout << ans << endl;
    // assert(false);
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