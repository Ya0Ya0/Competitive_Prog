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
void Solve()
{
    int n, d;
    cin >> n >> d;
    // read(ent, n);
    vector<int>ent(n),cl(n);
    for(int i =0;i <n;i++)cin >> ent[i] >> cl[i];
    read(days, d);
    vector<ll> dp(n+2);
    ll ans = 0, cur = 0, len = 0,curD=0;
    for (int i = 0; i < n; i++)
    {
        len++;
        ll curans =LONG_LONG_MAX;
        cur += ent[i];
        
        for (int j = len-1; j >=1 ; j--)
        {
            dp[j] = min(cur,max(dp[j]+cl[i],dp[j-1]));
        }
        dp[0] = min(cur,dp[0]+cl[i]);
        if(curD>=d)break;
        if(days[curD] == i+1)
        {
            for(int j =0;j <= len;j++)
            {
                if(dp[j] == cur)
                {
                    curans = min(curans,len-j);
                }
            }
            if(curans == LONG_LONG_MAX)
            {
                cout << -1 <<"\n";return;
            }
            curD++;
            ans+=curans;
            fill(all(dp),0);
            cur =0;
            len=0;
        }
    }
    cout << ans <<"\n";
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