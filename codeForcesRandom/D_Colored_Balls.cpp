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
ll const mod = 998244353;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a + mod) % mod;
        a = (a * a + mod) % mod;
        b /= 2;
    }
    return r;
}
// ll const mod = 998244353;
void Solve()
{
    int n;
    cin >> n;
    read(ent,n);
    sort(all(ent));
    ll max = accumulate(all(ent), 0LL);
    vector<ll> dp(max + 1, 0);
    dp[0]=1;
    ll ans =0;
    for(int i =0;i < n;i++)
    {
        for(int j = max; j >= ent[i];j--)
        {
            // if(dp[j - ent[i]] > 0 && ent[i] > (j+1)/2)
            // {
            //     ans = (ans + (ent[i]-(j+1)/2))*dp[j-ent[i]] % mod;
            //     cout << j << " " << (ent[i]-(j+1)/2)*dp[j-ent[i]] << "\n";
            // }
            dp[j] = (dp[j] + dp[j - ent[i]])%mod;

        }
    }
    // cout <<"ans  "<<ans << "\n";
    for(int i =0;i <n;i++)
    {
        for(int j =0;j < ent[i];j++)
        {
           ans = ans + (ent[i] - (ent[i] + j+1)/2)*dp[j] % mod;
           ans = ans % mod;
        //    cout << j+ent[i] <<" " << (ent[i] - (ent[i] + j+1)/2)*dp[j] << "\n";
        }
    }
    // cout <<"ans  "<<ans << "\n";
    for(int i =0    ;i <= max;i++)
    {
        if(dp[i] > 0)
        {
            ans = (ans + ((i + 1) / 2) * dp[i]) % mod;
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
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}