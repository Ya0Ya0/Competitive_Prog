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
ll inf = LONG_LONG_MAX;
void Solve()
{
    int n;
    cin >> n;
    vector<ll> ent(n);
    for (auto &e : ent)
        cin >> e;
    vector<vector<ll>> dp(n + 3, vector<ll>(5, -inf));
    // dp[n][2] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 2; j >=0; j--)
        {
            dp[i][j] = dp[i+1][j];
            if(j == 0)
            {
                dp[i][j] = max(dp[i][j], ent[i] + i + dp[i+1][j+1] );
            }
            if(j == 1)
            {
                dp[i][j] = max(dp[i][j], ent[i] + dp[i+1][j+1] );
            }
            if(j == 2)
            {
                dp[i][j] = max(ent[i] - i,dp[i][j]);
            }
        }
    }
    // dp[n + 1][3] = 0;
    // for (int i = n; i >= 1; i--)
    // {

    //     for (int j = 3; j >= 0; j--)
    //     {

    //         dp[i][j] = max(dp[i][j], dp[i + 1][j]);
    //         if (j == 0)
    //         {
    //             dp[i][j] = max(dp[i][j], ent[ i-1] + i + dp[i + 1][j + 1]);
    //         }
    //         else if (j == 1)
    //         {
    //             dp[i][j] = max(dp[i][j], ent[ i-1] + dp[i + 1][j + 1]);
    //         }
    //         else if (j == 2)
    //         {
    //             dp[i][j] = max(dp[i][j], ent[ i-1] - i + dp[i + 1][j + 1]);
    //         }
    //     }
    // }
    cout << dp[0][0] << "\n";
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