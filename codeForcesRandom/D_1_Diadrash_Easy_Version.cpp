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
void init() {};
void Solve()
{
    ll n,q;
    cin >> n >> q;
    // read(ent,n);
    vector<pair<ll, ll>> pairs(q);
    map<ll, ll> mp1,mp2;
    for (auto &[a, b] : pairs)
    {
        cin >> a >> b;
        mp1[b] =mp1.count(b)? min(mp1[b],a) : a;
        mp2[a] = max(mp2[a],b);
    }
    auto que = [](int l, int r)->ll
    {
        cout << "? " << l << " " << r << "\n";
        fflush(stdout);
        ll a;
        cin >> a;
        fflush(stdout);
        return a;
    };
    ll l = 0, r = n+1;
    // while (r - l > 1)
    // {
    //     ll mid = (l + r) >> 1;
    //     ll rr = que(l+1, mid);
    //     if (rr)
    //     {
    //         r = mid;
    //     }
    //     else
    //     {
    //         l = mid;
    //     }
    // }
    ll z = que(1,n/2);
    // if(z)r = n/2;
    // else r
    vector<pair<ll,ll>>pos;
    // int pp = r;
    if(z){
        for(ll i =0;i <= n/2;i++){
            if(mp2.count(i) )
                pos.push_back({i,mp2[i]});
        }
    }else{
        for(ll i = n;i>=n/2;i--){
            if(mp1.count(i) )
                pos.push_back({mp1[i],i});
        }
    }
    ll ans = 0;
    for(auto [a,b] :pos){
        ans = max(que(a,b),ans);
    }
    cout << "! " << ans <<"\n";
    fflush(stdout);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}