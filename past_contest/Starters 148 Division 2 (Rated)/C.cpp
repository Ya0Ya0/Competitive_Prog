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
ll mod = 1000000000 + 7;
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return r;
}
void Solve()
{
    ll n, p;
    cin >> n >> p;
    vector<ll> ent(n), vals(n);
    vals[n - 1] = 1;
    for (auto &e : ent)
        cin >> e;
    sort(all(ent));
    for (int i = 0; i < n - 1; i++)
    {
        ll z = ent[i];
        while (z <= ent[i + 1])
        {
            z *= 2;
            vals[i]++;
        }
    }
    ll k = accumulate(all(vals), 0);
    ll cc = p / k;
    ll res = p % k;
    if (res)
        for (int i = 0; i < n - 1; i++)
        {
            ll z = min(vals[i], res);
            res -= z;
            ent[i] = (ent[i] * elevar(2, z)) % mod;
            if (!res)
                break;
        }
    if (cc)
        for (int i = 0; i < n; i++)
        {
            ent[i] = (ent[i] * elevar(2, vals[i] * cc)) % mod;
        }
    ll ans = 0;
    for(int i =0; i < n; i++)
    {
        ans= (ans+ent[i])%mod;
    }
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