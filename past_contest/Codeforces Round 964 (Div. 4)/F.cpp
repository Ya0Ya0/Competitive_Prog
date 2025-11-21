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
ll mod = 1e9 + 7;
void Solve()
{
    auto comb = [&](ll a, ll b)
    {
        if (a > b)
            return 0LL;
        ll e = b - a;
        ll ans = 1;
        for (ll i = b; i > e; i--)
        {
            ans = (ans * i) ;
        }
        ll s = 1;
        for (ll i = 2; i <= a; i++)
        {
            s = (s * i) ;
        }
        // if (ans < s)
        //     ans += mod;
        // ans = (ans / s) % mod;
        // s = 1;
        // for (ll i = 2; i <= e; i++)
        // {
        //     s = (s * i) % mod;
        // }
        // if (ans < s)
        //     ans += mod;

        ans = (ans / s) % mod;
        return ans;
    };
    int n, k;
    cin >> n >> k;
    int o = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
            o++;
        else
            c++;
    }
    ll ans = 0;
    if (o < (k + 1) / 2)
    {
        cout << 0 << "\n";
        return;
    }
    if (k > 1)
        ans += (comb((k + 1) / 2, o) * comb(k / 2, c)) % mod;
    ans = (ans + comb(k, o)) % mod;
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