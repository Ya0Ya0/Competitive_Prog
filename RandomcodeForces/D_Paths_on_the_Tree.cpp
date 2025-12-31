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
void init(){};
void Solve()
{
    ll n,k; 
    cin >> n >> k;
    
    vector<vector<ll>>g(n);
    for(int i =1;i <n;i++){
        ll p;cin >> p;
        // g[i].push_back(p-1);
        g[p-1].push_back(i);
    }
    read(val,n);
    vector<map<ll,ll>>dp(n);
    auto dfs = [&](auto self,ll nd,ll p, ll k){
        if(dp[nd].count(k)){
            return dp[nd][k];
        }
        int cnt = g[nd].size();
        ll ans =0;
        if(cnt == 0)
        {
            dp[nd][k] = ans+val[nd]*k;
            return dp[nd][k];
        }
        if( k%cnt == 0){
            for(auto e : g[nd])
            {
                if(e!=p){
                    ans+=self(self,e,nd,k/cnt);
                }
            }
            dp[nd][k] = ans+val[nd]*k;
            return dp[nd][k];
        }else{
            vector<ll>dp1,dp2,df(cnt);
            for(auto e : g[nd])
            {
                if(e!=p){
                    dp1.push_back(self(self,e,nd,k/cnt));
                    dp2.push_back(self(self,e,nd,k/cnt+1));
                }
            }
            for(int i =0;i <cnt;i++)
            {
                df[i] = dp2[i]-dp1[i];
            }
            sort(all(df));
            reverse(all(df));
            for(int i =0;i <cnt;i++)
            {
                ans+=dp1[i];
            }
            for(int i =0;i < k%cnt;i++)
            {
                ans+=df[i];
            }
            dp[nd][k] = ans + val[nd]*k;
            return dp[nd][k];
        }

    };
    ll ans = dfs(dfs,0,-1,k);
    cout << ans <<"\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}