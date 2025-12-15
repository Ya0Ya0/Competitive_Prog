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
// ll dp[5005][5005];
void Solve()
{
    int n,m;
    string s,k;cin >> s >> k;
    // for(int i =0;i <n;i++)
    //     for(int j =0;j <m;j++)
    //         dp[i][j] = LONG_LONG_MAX;
    n = s.size(),m = k .size();
    vector<vector<ll>>dp(n+5,vector<ll>(m+5,LONG_LONG_MAX/7));
    dp[0][0] = 0;
    dp[1][0] = 1;
    dp[0][1] = 1;
    for(int i =0;i <n;i++)dp[i][0] = i;
    for(int i =0;i <m;i++ ) dp[0][i] = i;
    for(int i =0;i < n;i++)
    {
        for(int j =0;j < m;j++ ){
            dp[i+1][j+1] = min({dp[i+1][j+1],dp[i][j]+1});
            if(s[i] == k[j]){
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);
            }
            else{
                dp[i+1][j+1] = min({dp[i+1][j+1],dp[i+1][j]+1,dp[i][j+1]+1});
            }
        }
    }
    cout << dp[n][m] <<"\n";
    // cin >> n;
    // read(ent,n);
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