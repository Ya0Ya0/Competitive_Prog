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
int ttt = 0;
void Solve()
{
    ttt++;
   
    ll k,n ;cin >> n >> k;
    //  if(ttt == 901)
    // {
    //     cout << n << k << "\n";return;
    // }
    auto bs = [&](ll l,ll r,ll t)
    {
        while(r - l > 1)
        {
            ll mid = (r+l)/2;
            ll vmid = mid * (mid+1)/2 + k * (mid+1);
            if(vmid > t)
                r = mid;
            else l = mid;
        }
        return l;
    };
    auto calc = [&](ll ini,ll cnt)
    {
        ll ans = cnt*(cnt+1)/2 + cnt*ini;
        ll l = (ini-1)*(ini)/2;
        ll z = ini+cnt-1;
        ll r = z*(z+1)/2;
        return r - l;
    };
    ll tar = (n*(n-1)/2 + n*(k))/2;
    ll z = bs(0,n,tar);
    ll l = z * (z+1)/2 + k*(z+1);    
    ll r = calc(z+1, n - (z+1)) + (k * (n - (z+1)));
    ll l2 = (z+1) * (z+2)/2 + k*(z+2);
    ll r2 = calc(z + 2, n - (z+2)) + k * (n - (z+2));
    // if(z + 2>=n)
    // {

    // }
    ll ans = min(abs(r - l), abs(l2-r2));
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