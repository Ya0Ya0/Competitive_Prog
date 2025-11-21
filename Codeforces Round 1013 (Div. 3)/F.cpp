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
    ll mod = 998244353;
    ll n, m, d;
    cin >> n >> m >> d;
    vector<string> v(n);
    vector<vector<ll>> dis(n + 5, vector<ll>(m + 5));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++)
    {
        dis[0][i] = v[0][i] == 'X';
    }
    vector<ll> pre(m + 5);
    for (int i = 0; i < n; i++)
    {        
        if (i > 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'X')
                {
                    ll dd = sqrtl(d * d - 1);
                    ll l = max(j - dd, 0LL);
                    ll r = min(j + dd, m - 1);
                    dis[i][j] = ( pre[r + 1] - pre[l] + mod) % mod;
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            pre[j + 1] = (pre[j] + dis[i][j]) % mod;
        }
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'X')
            {
                ll dd = sqrtl(d * d);
                ll l = max(j - dd, 0LL);
                ll r = min(j + dd, m - 1);
                dis[i][j] = (dis[i][j] + pre[r + 1] - pre[l]-dis[i][j] + mod) % mod;
            }
        }
        for (int j = 0; j < m; j++)
        {
            pre[j + 1] = (pre[j] + dis[i][j]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = (ans + mod + dis[n - 1][i]) % mod;
    }
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