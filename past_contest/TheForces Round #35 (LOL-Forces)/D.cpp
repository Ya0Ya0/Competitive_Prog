#include "bits/stdc++.h"
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
const ll mod = 1e9 + 7;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a)%mod;
        a = (a * a)%mod;
        b /= 2;
    }
    return r;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    string ppp;cin >> ppp;
    if (m < n)
    {
        cout << 0 << '\n';
        return;
    }
    ll ans = 1;
    ll ws = (m - n) / 2;
    if(ws == 0)
    {
        cout << 1 << '\n';
        return;
    }
    vector<vector<ll>> dp(n + 3, vector<ll>(ws + 2));
    dp[0][0] = 0;
    for (int i = 1; i <= n+1 ; i++)
    {
        dp[i][0] = (dp[i-1][0] + 26)%mod;
        for (int j = 1; j < ws; j++)
        {
            dp[i][j]=(dp[i-1][j] + (dp[i][j-1]*26)%mod)%mod;
        }
    }
    cout << dp[n+1][ws-1]+1;
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