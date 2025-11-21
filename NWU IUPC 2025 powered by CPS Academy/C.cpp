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
ll mod = 1e9 + 7;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a)%mod;
        a = (a * a)%mod;
        b /= 2;
    }
    return r;
}
void Solve()
{
    ll n,p; 
    cin >> n >> p;
    read(pr,p);
    read(ent,n);
    vector<vector<ll>>pd(n);
    map<ll,vector<ll>>vp;
    for(ll i =0; i <n;i++)
    {
        ll e = ent[i];
        for(auto P : pr)
        {
            if(e%P == 0)
            {
                pd[i].push_back(P);
            }
        }
        vp[ent[i]] = pd[i];
    }   
    map<ll,ll>dp;
    

    ll ans = 0;
    for(ll i =0;i  <n;i++)
    {
        for(ll j =0;j < (1LL << pd[i].size()); j++)
        {
            ll cur =1;
            for(ll k =0; 1LL << k <= j;k++)
            {
                if(1LL << k & j)cur*=pd[i][k];
            }
            if(cur)
                dp[cur]++;
        }
    } 
    auto z = dp.rbegin();
    for(auto &[a,b] : dp)
    {
        b = ( (elevar(2,b)-1)) % mod;
    }
    while(z!=dp.rend())
    {
        auto &[a,b] = *z;
        ans= (ans+a*b%mod) %mod ;
        
        vector<ll>fac;
        for(auto P : pr)if(a%P == 0)fac.push_back(P);
        for(ll j =0;j < (1LL << fac.size()); j++)
        {
            ll cur =1;
            for(ll k =0; 1LL << k <= j;k++)
            {
                if(1LL << k & j)cur*=fac[k];
            }
            if(cur)
                dp[cur]=(dp[cur] - b+mod )%mod;
        }
        // for(auto P : pr)
        // {
        //     if(a%P ==0)dp[a/P]=(dp[a/P]-b + mod)%mod;
        // }
        z = next(z);
    }
    
    cout << (ans+mod)%mod <<"\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}