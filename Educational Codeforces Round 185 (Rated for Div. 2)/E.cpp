#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
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
ll mod = 998244353;
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a) %mod;
        a = (a * a)%mod;
        b /= 2;
    }
    return r;
}
void Solve()
{
    ll n,m; 
    cin >> n >> m;
    // read(ent,n);
    vector<pair<ll,ll>>cons(m),nw;
    for(auto &[a,b] : cons)cin >> a >> b;
    sort(all(cons),[](pair<ll,ll> a, pair<ll,ll>b  ){
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    nw.push_back(cons.front());
    vector<bool>op;
    op.push_back(false);
    // for(auto &[a,b] : cons){
    //     if(b - a ==1)cout << 
    // }
    for(ll i =1;i < m;i++){
        auto &[a,b] = nw.back();
        if(b > cons[i].first){
            b = max(b,cons[i].second);
        }
        else if(b == cons[i].first ){
            nw.push_back({cons[i].first+1, cons[i].second});
            op.push_back(true);
        }else{
            nw.push_back({cons[i].first, cons[i].second});
            op.push_back(false);
        }
    }
    ll ans = 1;
    ll cnt = 0;
    ll mn  = nw[0].first,mx = nw[0].second;
    for(auto [a,b] : nw){
        ans = ans * elevar(2,b-a) %mod;
        cnt+=b-a+1;
        mn = min(mn,a);
        mx=  max(mx,b);
    }
    ll z =1,o = 1;
    if(mn-1 > 0)
     z= (elevar(2,mn-1)+ mod)%mod;
     if(mx!= n)
     o = (elevar(2,n-mx) + mod)%mod;
    ans = ((ans * z %mod)) * o % mod;
    cout << ans <<"\n";

    // for(auto [a,b] : cons)cout << a << " " << b <<"\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // for(int i =0;i <205;i++)
    // {
    //     if(elevar(2,i) == 570529459LL){
    //         cout << i <<"\n";return 0;
    //     }
    // }
    // ll k = elevar(2,23)*elevar(2,175) %mod;
    // cout << k <<"\n";
    // return 0;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}