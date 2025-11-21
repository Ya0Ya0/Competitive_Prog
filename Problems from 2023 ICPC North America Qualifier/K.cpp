#include "bits/stdc++.h"
using namespace std;
#define ll long long

// Replace pq alias with multiset (min-heap behavior)
#define pq multiset<pair<ll, pair<ll, ll>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
        cin >> e;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
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
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> v(n + 1), tree(n + 1);
    vector<ll> par(n + 5);
    vector<ll> sz(n + 5, 1);
    vector<pq> queues(n);
    iota(all(par), 0);

    auto g_par = [&](auto self, ll a) -> ll
    {
        if (par[a] == a)
            return a;
        return par[a] = self(self, par[a]);
    };

    auto merge = [&](ll a, ll b) -> void
    {
        ll para = g_par(g_par, a), parb = g_par(g_par, b);
        if (sz[para] > sz[parb])
        {
            sz[para] += sz[parb];
            par[parb] = para;
        }
        else
        {
            sz[parb] += sz[para];
            par[para] = parb;
        }
    };

    pq q;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        q.insert({w, {a, b}});
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }

    ll ans = 0;
    while (!q.empty())
    {
        auto it = q.begin();
        auto [w, e] = *it;
        auto [a, b] = e;
        q.erase(it);
        if (g_par(g_par, a) == g_par(g_par, b))
            continue;
        merge(a, b);
        ans += w;
        tree[a].push_back({b, w});
        tree[b].push_back({a, w});
    }

    iota(all(par), 0);
    sz.assign(n + 5, 1);
    ll tans = ans;

    auto dfs = [&](auto self, ll node, ll parent) -> pq*
    {
        vector<pq*> sons;
        for (auto e : tree[node])
        {
            if (e.first == parent)
                continue;
            pq* q = self(self, e.first, node);

            while (!q->empty())
            {
                auto it = q->begin();
                auto [w, ed] = *it;
                auto [a, b] = ed;
                q->erase(it);
                if (g_par(g_par, a) == g_par(g_par, b))
                    continue;
                tans = max(tans, ans - e.second + w);
                break;
            }
            sons.push_back(q);
        }

        pq *cur;
        for (ll i = 0; i < sons.size(); i++)
        {
            if (sons[i]->size() > sons[0]->size())
                swap(sons[i], sons[0]);
        }

        for (auto e : tree[node])
        {
            if (e.first == parent)
                continue;
            merge(node, e.first);
        }

        if (sons.empty())
        {
            cur = &(queues[node]);
            for (auto e : v[node])
            {
                if (e.first == parent)
                    continue;
                if (g_par(g_par, e.first) == g_par(g_par, node))
                    continue;
                cur->insert({e.second, {e.first, node}});
            }
            return cur;
        }

        cur = sons[0];
        for (auto e : v[node])
        {
            if (e.first == parent)
                continue;
            if (g_par(g_par, e.first) == g_par(g_par, node))
                continue;
            cur->insert({e.second, {e.first, node}});
        }

        for (ll i = 1; i < sons.size(); i++)
        {
            // multiset<ll>ss,kk;
            // kk.insert(all(ss));
            cur->insert((sons[i])->begin(),sons[i]->end());
            sons[i]->clear();
        }

        return cur;
    };

    dfs(dfs, 0, -1);
    cout << tans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--)
    {
        Solve();
    }
}
