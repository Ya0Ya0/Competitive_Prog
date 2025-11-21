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
    ll n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<ll>> grid(n, vector<ll>());
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    vector<bool> vis(n);
    vector<vector<ll>> parent(n);
    vector<bool> good(n);
    set<ll> ans;
    vector<ll> low(n, -1), disc(n, -1);
    ll time = 0;
    auto bfs2 = [&](ll u, ll p, auto self) -> void
    {
        // if (!good[u])
        //     return;
        disc[u] = low[u] = ++time;
        for (auto v : grid[u])
        {
            if (v == p  )
                continue;
            if (disc[v] == -1)
            {
                self(v, u, self);
                low[u] = min(low[u], low[v]);
                if (low[v] >= disc[u] )
                {
                    ans.insert(u + 1);
                }
            }
            else
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    };
    vis[s - 1] = 1;
    bfs2(s - 1, -1,  bfs2);
    auto dfs = [&](ll u, ll p, auto self) -> bool
    {
        bool ans = 0;

        for (auto v : grid[u])
        {
            if (v == p)
                continue;
            if (!vis[v])
            {
                vis[v] = 1;
                parent[v].push_back(u);
                ans |= self(v, u, self);
            }
            else
            {
                ans |= good[v];
            }
        }
        if (u == e - 1)
        {
            good[u] = 1;
            return 1ll;
        }
        if (ans)
        {
            good[u] = 1;
        }
        return ans;
    };
    dfs(s - 1, -1, dfs);
    
    
    // auto bfs = [&](ll u) -> void
    // {
    //     queue<ll> q;
    //     q.push(u);
    //     vis[u] = 1;
    //     dis[u] = 0;
    //     while (!q.empty())
    //     {
    //         ll uu = q.front();
    //         q.pop();
    //         for (auto v : grid[uu])
    //         {
    //             if (!vis[v])
    //             {
    //                 vis[v] = 1;
    //                 dis[v] = dis[uu] + 1;
    //                 if (good[v])
    //                 {
    //                     dss[dis[v]].push_back(v);
    //                     parent[v].push_back(uu);
    //                 }
    //                 q.push(v);
    //             }
    //             else
    //             {
    //                 if (good[v])
    //                     parent[v].push_back(uu);
    //             }
    //         }
    //     }
    // };
    // bfs(s - 1);
    for(auto e : ans)
    {
        if(!good[e-1])
        {
            ans.erase(e);
        }
    }
    ans.insert(s);
    ans.insert(e);
    cout << ans.size() << "\n";
    for (auto e : ans)
    {
        cout << e << "\n";
    }
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