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
    ll n, k, x;
    cin >> n >> k >> x;
    read(ent, n);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + ent[i];
    }
    auto bs = [&](ll xx)
    {
        ll l = 1, hi = n * k;

        while (hi - l > 1)
        {
            ll mid = (l + hi) / 2;
            ll cnt = mid / n;
            ll res = mid % n;
            ll sum = pre[n] * cnt + pre[res] - pre[xx-1];
            if (sum >= x)
                hi = mid;
            else
                l = mid;
        }
        return hi;
    };
    ll ans = 0;
    for(int i =0;i < n;i++)
    {
        ll a = bs(i+1);
        ll cnt = a / n;
        ll res = a % n;
        ll sum = pre[n ] * cnt + pre[res] - pre[i];
        if( sum < x) continue;
        ll j = n*k - a+i;
        ll zz = (n*k - a+i)%n;
        if(zz < i)j-=n;
        ll ax =(j)/k;
        ans+=ax;
    }
    cout << ans <<"\n";
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