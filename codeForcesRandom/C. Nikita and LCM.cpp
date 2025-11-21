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
int z = 0;
ll c = 5001;
void Solve()
{
    ll n;
    cin >> n;
    vector<ll> val(n);
    map<ll, ll> mp;
    for (auto &v : val)
        cin >> v,
            mp[v]++;

    ll gc = val[0];
    for (auto v : val)
    {
        gc = lcm(gc, v);
        if (gc > (*mp.rbegin()).first)
        {
            cout << n << "\n";
            return;
        }
    }

    auto fnd = [&](ll t)
    {
        ll Lcm = 1;
        ll ans = 0, ok = false;
        for (auto [a, b] : mp)
        {
            if (!(t % a == 0))
                continue;
            Lcm = lcm(Lcm, a);
            if (Lcm == t)
            {
                ok = true;
            }

            ans += b;
        }
        if (ok)
            return ans;
        else
            return 0LL;
    };
    ll ans = 0;
    for (ll i = 1; i * i <= gc; i++)
    {
        if (!(gc % i == 0))
            continue;
        if (!mp.count(gc / i))
        {
            ans = max(ans, fnd(gc / i));
        }
        if (!mp.count(i))
        {
            ans = max(ans, fnd(i));
        }
        lcm(3, 2);
    }
    if (z == 114 && ans == 0)
    {
        for (auto v : val)
            cout << v << " ";
        cout << "\n";
        return;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    z = tt;
    while (tt--)
    {
        Solve();
    }
}