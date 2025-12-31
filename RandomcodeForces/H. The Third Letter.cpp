#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
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
ll c = 5001;
const ll inf = LONG_LONG_MAX;
void Solve()
{
    int n, q;
    cin >> n >> q;
    map<pair<ll,ll>,ll>d;
    vector<vector<int>> ent(n + 2);
    bool ok = true;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ll w;
        cin >> w;
        ent[a].push_back(b);
        ent[b].push_back(a);
        if (d.count({a,b}) && d[{a,b}] != w)
        {
            ok = false;
        }
        d[{a,b}] = w;
        d[{b,a}] = -w;
    }
    vector<bool> vis(n);
    vector<ll> CDis(n);
    if(!ok)
    {
        cout << "NO\n";return;
    }
    auto dfs = [&](auto self, int nd) -> bool
    {
        bool ans = true;

        vis[nd] = true;
        for (auto e : ent[nd])
        {
            if (vis[e])
            {
                ll ck = CDis[nd] + d[{nd,e}] - CDis[e];
                if (ck != 0)
                {
                    ans = false;
                }
            }
            else
            {
                CDis[e] = CDis[nd] + d[{nd,e}];
                ans &= self(self, e);
            }
        }
        return ans;
    };
    ll ans = true;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            ans &= dfs(dfs, i);
    }
    if (ans)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}