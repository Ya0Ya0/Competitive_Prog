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
string r = "narek";
set<char>z(all(r));
ll asd = LONG_LONG_MAX; 
void Solve()
{
    int n,m;cin >> n >> m;
    vector<string>ent(n);
    for(auto &e : ent)cin >> e;
    map<int,ll>dp;
    
    dp[0] = 0;
    for(int i =1;i < r.length();i++)
    {
        dp[i] = -LONG_MAX;
    }
    for(int i =0;i <n;i++)
    {        
        map<int,ll>nwdp = dp;
        for(int j =0;j <5;j++)
        {
            if(dp[j] == -LONG_MAX)continue;
            ll it = j;
            ll tot = 0;
            ll fnd = 0;
            for(int k =0;k <m;k++)
            {
                if(ent[i][k] == r[it])
                {
                    it = (it+1)%5;
                    if(it == 0)fnd++;
                }
                if(z.find(ent[i][k])!=z.end())
                {
                    tot++;
                }
            }
            nwdp[it] = max(nwdp[it],fnd*5*2 - tot + dp[j]);
        }
        for(auto [a,b] : nwdp)
        {
            dp[a] = max(dp[a],b);
        }
    }
    ll ans =0;
    for(int i =0;i <5;i++)
    {
        ans = max(ans,dp[i]);
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