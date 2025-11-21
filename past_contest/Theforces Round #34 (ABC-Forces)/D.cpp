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
    ll sum = 0;
    int n;cin >>n;
    ll ans =0;
    vector<pair<ll,ll>>ent(n);
    ll mxx = 0,mxy = 0;;
    for(auto &[a,b] : ent)
    {
        cin >> a >> b;
        mxx += max(b,a);
        sum+=min(a,b)*min(a,b);
    }
    
    bool f = true;
    for(auto [a,b] : ent)
    {
        mxx-= max(a,b);
        sum-=min(a,b)*min(a,b);
        ll cur = (a+b+mxx)* (a+b+mxx) + sum;
        ans = max(ans,cur);
        mxx+=max(a,b);
        sum+=min(a,b)*min(a,b);
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