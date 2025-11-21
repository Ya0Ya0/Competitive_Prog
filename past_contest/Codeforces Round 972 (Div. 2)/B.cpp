#include"bits/stdc++.h"
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
    ll n,t,q;cin >> n >> t >> q;
    set<ll>tp;
    for(int i =0;i <t;i++)
    {
        ll a;cin >> a;
        tp.insert(a);
    }
    for(int g =0;g <q; g++)
    {
        ll que;cin >> que;
        ll l = -1,r = -1;
        auto rp = tp.lower_bound(que);
        
        if(rp!=tp.end())
        {
            r = *rp;
        }
        auto lp = prev(rp);
        if(rp!=tp.begin())
        {
            l = *lp;
        }
        ll ans ;
        if(l == -1)
        {
            ans = r - 1;
        }
        else if(r == -1)
        {
            ans = n - l;
        }
        else{
            // ll k = min(que - l, r - que);
            // ans = k-1;
            // if(r-que > que - l)
            // {
            //     r-= ans;
            //     ll avr = (r+que+1)/2;
            //     ans+=avr-que;
            // }
            // else{
            //     l+=ans;
            //     ll avr = (l+que+1)/2;
            //     ans+=que - avr;
            // }
            ll avr = (l + r + 1)/2;
            ans = min(avr - l, r - avr);
        }
        cout << ans << "\n";
    }
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