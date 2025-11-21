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
    map<ll, vector<ll>> mp;
    map<ll, ll> m;
    int n;
    cin >> n;
    ll xord = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        mp[log2(a)].push_back(a);
        xord |= a;
    }
    for (auto [a, v] : mp)
    {
        ll temp = 0;
        mx = max(a+1, mx);
        for (auto val : v)
        {
            temp |= val;
        }
        m[a] = temp;
    }

    for (int i = 0; i < mx; i++)
    {
        ll z = 1 << i;
        ll k = xord & (z);
        if ((k )!= z)
        {
            mx = i;
            xord = 0;
            for (auto [a, b] : m)
            {
                if (a < mx)
                {
                    xord|=b;
                }
            }
        }
    }
    ll ans = 0;
    for(auto [a,b] : mp)
    {
        if(a >= mx)
        {
            ans+=b.size();
        }
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