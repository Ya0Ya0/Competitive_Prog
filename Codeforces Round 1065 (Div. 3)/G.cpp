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
const ll mod = 1e6 + 3;
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a )%mod;
        a = (a * a) %mod;
        b /= 2;
    }
    return r;
}

ll fact[mod *50+10] = {};
void Solve()
{
    int n;
    cin >> n;
    read(a, n);
    read(b, n);
    ll mx = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ll k = 0;
        ll cur = a[i];
        while (k < mx && cur < b[i])
        {
            cur *= 2;
            k++;
        }
        mx = min(mx, k);
    }
    ll x = 0;
    ll pw = 1LL << mx;
    ll ans = 1;
    for (int i = 0; i <= mx; i++)
    {
        vector<ll> vals;
        ll sum = 0;
        ll inv = 1;
        for (int j = 0; j < n; j++)
        {
            ll cur = a[j];
            ll rs =  b[j] - cur*pw;
            sum+=rs;
            inv = (inv * fact[rs])%mod;
            vals.push_back(rs);
            a[j] = cur;
        }
        x+=sum;
        inv = elevar(inv,mod-2);
        cout << fact[sum] << " " << fact[sum-1] <<"\n";
        ans = (ans * (inv * fact[sum])%mod)%mod; 
    }
    x+=mx;
    cout << x <<" " << ans << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    fact[0] = 1;
    for (int i = 1; i < mod *50; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    while (tt--)
    {
        Solve();
    }
}