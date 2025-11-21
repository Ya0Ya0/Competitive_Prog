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
    // int n;
    // cin >> n;
    // read(ent,n);
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<ll>> dp(a.length() + 5, vector<ll>(b.length() + 5, LONG_LONG_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= c.length(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(j > a.length() || i-j > b.length())continue;
            if (j != 0)
                dp[j][i - j] = dp[j - 1][i - j] + (c[i - 1] != a[j - 1]);
            if (j != i)
                dp[j][i - j] = min(dp[j][i - j], dp[j][i - j - 1] + (c[i - 1] != b[i - j - 1]));
        }
    }
    cout << dp[a.length()][b.length()] << "\n";
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