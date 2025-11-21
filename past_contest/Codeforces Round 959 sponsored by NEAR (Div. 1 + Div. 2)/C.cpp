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
void Solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> ent(n);
    for (auto &e : ent)
        cin >> e;
    vector<ll> pre(n + 1);
    // pre[0] = ent[0];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + ent[i - 1];
    }
    ll ans = 0;
    vector<ll> vis(n + 2);
    ll c = 0;
    vector<ll> dp(n + 3);
    if(ent[n-1] > x)dp[n] = 1;
    else dp[n] = 0;
    for (int i = n; i > 0; i--)
    {
        if (pre[n] - pre[i-1]> x)
        {
            int z = lower_bound(all(pre),pre[i-1] + x+1) - pre.begin();
            dp[i] = dp[z+1] + 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        ans+=dp[i+1];
    }
    cout << n*(n+1)/2 - ans << "\n";return;
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