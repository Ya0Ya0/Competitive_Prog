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
ll const MAXN = 1e6 + 6;
vector<ll> dp(MAXN);
void Solve()
{

    int n;
    cin >> n;
    read(ent, n);
    set<ll> num,re;
    for (auto e : ent)
    {
        num.insert(e);
        re.insert(MAXN-e);
    }
    ll ans =0;
    for (auto a : num)
    {
        auto z = re.lower_bound(MAXN-(a-2));
        auto k = re.lower_bound(MAXN-(a-1));
        ll n1=0,n2=0;
        if(z!=re.end() )
        n1 = MAXN-*z;
        if(k!=re.end() )
        n2 = MAXN-*k;
        dp[a] = max(dp[n2],dp[n1]+1);
        ans = max(ans,dp[a]);
    }
    for(auto e : num)dp[e]=0;
    cout << ans <<"\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}