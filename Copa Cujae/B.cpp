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
    int n;
    cin >> n;
    vector<ll> x(n), sz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> sz[i];
    }
    ll dp[n + 1][3];
    // dp[x][0]= l
    // dp[x][1]= r
    // dp[x][0]= ignore

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
        if (i == 0)
        {
            dp[0][0] = 1;
            dp[0][2] = 1;
            if (i + 1 < n)
            {
                if (x[i] + sz[i] < x[i + 1])
                    dp[0][1] = 1;
            }
            else
                dp[0][1] = 1;
            continue;
        }
        ll bs = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][2] = bs;
        if (x[i] - sz[i] > x[i - 1])
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        }
        if (x[i] - sz[i] > x[i - 1] + sz[i - 1])
        {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
        }
        if (i + 1 == n)
        {
            dp[i][1] = bs + 1;
            continue;
        }
        if (x[i] + sz[i] < x[i + 1])
        {
            dp[i][1] = bs + 1;
        }
    }
    ll ans = max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}