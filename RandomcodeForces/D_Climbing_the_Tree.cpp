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
ll const mod = 1e9 + 7;

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
void Solve()
{
    int n;
    cin >> n;
    // read(ent,n);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        v--;
        u--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    auto dfs = [&](auto self, int node, int parent) -> void
    {        
        vector<vector<ll>> child_dp(adj[node].size(), vector<ll>(2, 0));
        int i = 0;
        for (int child : adj[node])
        {
            if (child == parent)
                continue;
            self(self, child, node);
            if (i == 0)
            {
                child_dp[i][0] = dp[child][0];
                child_dp[i][1] = dp[child][1];
            }
            else{
                child_dp[i][0] = (child_dp[i - 1][0] * dp[child][0] + child_dp[i - 1][1] * dp[child][1]) % mod;
                child_dp[i][1] = (child_dp[i - 1][0] * dp[child][1] + child_dp[i - 1][1] * dp[child][0]) % mod;
            }
            i++;
        }

        dp[node][0] = elevar(2, n - 1) + (child_dp.size() > 0 ? child_dp.back()[0] : 0);
        dp[node][1] = elevar(2, n - 1) +( child_dp.size() > 0 ? child_dp.back()[1] : 0);
        cout << dp[node][0] << " " << dp[node][1] << "\n";
        ans = (ans + dp[node][1]) % mod;
    };
    dfs(dfs, 0, -1);
    cout << ans << "\n";
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