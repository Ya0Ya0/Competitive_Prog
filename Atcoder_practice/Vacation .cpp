#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : ent)   \
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
const ll INF = LONG_LONG_MAX;
void Solve()
{
    int n;cin >> n;
    vector<vector<ll>>a(n,vector<ll>(3+1));
    for(int i =0;i <n;i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    if(n < 3)
    {
        int s =0;
        for(int i =0;i <n;i++)
        {
            s+= * max_element(all(a[i]));
        }
        cout << s;
        return;
    }
    map<ll,ll>dp;
    
    dp[1] = a[0][1];
    dp[2] = a[0][2];
    dp[3] = a[0][3];    
    for(int i = 1;i <n;i++)
    {
        map<ll,ll>ndp;
        for(int j =1;j <=3;j++)
        {
            
            for(auto [k,s] : dp)
            {
                if(k!=j)
                {
                    ndp[j] = max(ndp[j],s + a[i][j]);
                }
            }
            
        }
        dp = ndp;
    }
    ll ans =0;
    for(auto [_,cans] : dp)
    {
        ans = max(ans,cans);
    }
    cout << ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}