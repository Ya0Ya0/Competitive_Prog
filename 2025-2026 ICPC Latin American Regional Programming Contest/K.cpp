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
    ll n, k;
    cin >> n >> k;
    // read(ent,n);
    vector<pair<ll, ll>> v(n);

    ll mxx = LONG_LONG_MIN, mxy = LONG_LONG_MIN, mnx = LONG_LONG_MAX, mny = LONG_LONG_MAX;
    for (auto &[a, b] : v)
    {
        cin >> a >> b;
        mxx = max(mxx, a);
        mxy = max(mxy, b);
        mnx = min(mnx, a);
        mny = min(mny, b);
    }
    vector<pair<ll, ll>> mv{{k, k}, {-k, k}, {k, -k}, {-k, -k}};
    ll ans = 0;
    if(n == 1)
    {
        cout << 1 <<"\n";return;
    }
    exit(0);
    for(ll i =0;i <= k;i++)
    {
        ans = max(abs(mxx -mnx + i+1) * abs(mxy - mny+k-i+1),ans);
    }
    for (auto [a, b] : v)
    {
        for (auto [x, y] : mv)
        {
            ll na = a+x,nb = b+y;
            ll nmxx = max(mxx, na);
            ll nmnx = min(mnx, na);
            ll nmxy = max(mxy, nb);
            ll nmny = min(mny, nb);
            ans = max(ans,abs(nmxx -nmnx+1) * abs(nmxy - nmny+1)); 
        }
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
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}