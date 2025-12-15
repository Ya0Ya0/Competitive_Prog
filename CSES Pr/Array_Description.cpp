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
// const ll  MAXN = 1e5+5, MAXM = 103;
// ll dp[MAXN][MAXM];
void Solve()
{
    int n,m; 
    cin >> n >> m;
    read(ent,n);
    vector<ll>dp(m+5);
    if(ent[0] == 0){
        for(int i =1;i <=m;i++){
            dp[i] = 1;
        }
    }else{
        dp[ent[0]] = 1;
    }
    const ll mod= 1e9+7;
    for(int i =1;i < n;i++){
        vector<ll>ndp(m+5);
        if(ent[i] == 0){
            for(int j =1 ;j <= m;j++){
                ndp[j] = (ndp[j] + dp[j-1] + dp[j+1] + dp[j])%mod; 
            }
        }else{
            if(ent[i]+1 <= m)
                ndp[ent[i]] = (ndp[ent[i]] + dp[ent[i]+1])%mod; 
            if(ent[i]-1 >= 1)
                ndp[ent[i]] = (ndp[ent[i]] + dp[ent[i]-1])%mod; 
            ndp[ent[i]] = (ndp[ent[i]] + dp[ent[i]])%mod;
            
        }
        dp = ndp;
    }
    ll ans =0;
    for(int i =1;i <= m;i++){
        ans = (ans + dp[i])%mod;
    }
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
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}