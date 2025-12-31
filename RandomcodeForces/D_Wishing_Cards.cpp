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
    ll n, k;
    cin >> n >> k;
    read(ent, n);
    vector<vector<ll>> dp(k+1, vector<ll>(k+1));
    // ll dp[365][365];
    for (auto &e : ent)
        e = min(e, k);
    int pr = 0;
    ll ans = 0;
    ll skp = 0;
    for (int i = 0; i < n; i++)
    {
        if (ent[i] <= pr)
        {
            skp++;
            continue;
        }
        
        vector<ll>bs(k);        
        for(int j =0;j <=pr;j++){
            for(int cs =j;cs<=k;cs++){
                dp[cs][j] +=j * skp;
            }
        }
        vector<vector<ll>> ndp = dp;
        vector<vector<ll>> ndp2 = dp;
        for(int cs = 1; cs <= k;cs++){
            for(ll j =1;j <= k;j++){
            
                ndp2[cs][j] = max(dp[cs][j], ndp2[cs][j-1]);
                
            }   
        }
        for(int j =0;j <=pr;j++){
            for(int cs =j;cs<=k;cs++){
                ndp[cs][j] +=j;
                ans = max(ans,ndp[cs][j]);
            }
        }
        skp = 1;
        for(ll j =pr+1;j <= ent[i];j++){
            for(int cs = j; cs <= k;cs++){
                ndp[cs][j] = max(ndp[cs][j], ndp2[cs-j][pr]+j);
                ans = max(ans,ndp[cs][j]);
            }   
        }
        // for(int cs = 1; cs <= k;cs++){
        //     for(ll j =1;j <= ent[i];j++){
            
        //         ndp[cs][j] = max(ndp[cs][j], dp[cs][j-1]);
                
        //     }   
        // }
        skp = 0;
        pr = ent[i];
        dp = ndp;
    }
    for (int j = 0; j <= pr; j++)
    {
        for (int z = j; z <= k; z++)
        {
            dp[z][j] += j * skp;
            ans = max(ans,dp[z][j]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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