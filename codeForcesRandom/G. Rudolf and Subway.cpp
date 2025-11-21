#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
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
ll mn = 2*1e5 + 5;
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<ll>> cl(1e6 + 6);
    vector<vector<pair<ll, ll>>> g(n);
    map<ll, ll> vis;

    //
    vector<int>seenC(mn);
    map<ll, ll> dis;
    map<ll, ll> nodeC;
    //
    vector<set<int>>gcol(mn);
    //
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        cl[c].insert(a);
        cl[c].insert(b);
    }
    pq q;
    int s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << 0 << "\n";
        return;
    }
    s--, t--;
    for (auto [nd, c] : g[s])
    {
        q.push({1, c});
        dis[c] = 1;
        nodeC[c] = nd;
        seenC[c] = 1;;
    }
    auto dfs = [&](int node, int col)
    {
        vector<int> visn(n);
        stack<int> s;
        s.push((node));
        while (!s.empty())
        {
            auto cur = s.top();
            s.pop();

            visn[cur] = true;
            for (auto [a, b] : g[cur])
            {
                if (!visn[a])
                {
                    s.push(a);
                }
                // if(b!=)
                
            }
        }
    };

    while (!q.empty())
    {
        auto [dis, cur] = q.top();
        q.pop();

        dfs(nodeC[cur], cur);
    }
    ll ans = LONG_LONG_MAX;
    for(auto [a,b] : g[t])
    {
        ans=min(ans,dis[b]);
    }
    cout << ans << "\n";
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