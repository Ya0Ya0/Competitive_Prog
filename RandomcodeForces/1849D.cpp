#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
#define read(name, n)    \
    vector<ll> name(n);  \
    for (auto &e : name) \
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
ll c = 5001;
ll mod = 1e9 + 7;
void Solve()
{
    ll n;
    cin >> n;
    read(ent, n);
    vector<int> used(n);
    vector<vector<ll>> dp(n, vector<ll>(4, LONG_LONG_MAX/2));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ent[i] == 2 && !used[i])
        {
            used[i] = 1;
            ll k = i;
            while (k > 0 && ent[k] > 0)
            {
                used[--k] = 1;
            }
            k = i;
            while (k+1 < n && ent[k] > 0)
            {
                used[++k] = 1;
            }
            ans++;
        }
    }
    if (used[0])
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
    else
    {
        dp[0][0] = dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (used[i])
            dp[i][0] = dp[i][1] = dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
        if (!used[i])
        {
            dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]))+1;
            if (ent[i - 1] > 0)
            {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            }
            if (ent[i] > 0)
            {
                dp[i][2] = dp[i - 1][3] + 1;
            }
            if (i < n - 1 && ent[i + 1] > 0)
            {
                dp[i][3] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
                if (ent[i] > 0)
                    dp[i][3] = min(dp[i][3],dp[i-1][3]);
            }
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) + ans << "\n";
}
void init()
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}