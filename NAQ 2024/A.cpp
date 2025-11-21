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
    vector<pair<char, ll>> ent(n);
    // read(ent,n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ent[i].first >> ent[i].second;
    }
    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));
    vector<ll> mx(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                dp[i][j] = ent[i - 1].first == 'a' ? ent[i - 1].second : 0;
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (ent[i - 1].first == 'a')
                    dp[i][j] = max(dp[i - 1][j - 1] + ent[i - 1].second, dp[i][j]);
                else
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * ent[i - 1].second);
                }
            }
            mx[j] = max(mx[j], dp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << mx[i] << "\n";
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