#include <bits/stdc++.h>
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
ll mx = 5050;
void Solve()
{
    ll n; cin >> n;
    vector<ll>ent(n);
    map<ll,ll>mp,pos;
    for(auto &e : ent)
    {
        cin >> e;
        mp[e]++;
    }
    vector<ll>mod;
    for(auto [a,b] : mp)
    {
        mod.push_back(a);
        pos[a] = mod.size()-1;
    }
    ll ans = 0;
    
    vector<vector<ll>> dp(mp.size()+1, vector<ll>(mx));
    for (int j = 1; j <= mp.size(); j++)
    {
        for (int i = 1; i <= mp.size(); i++)
        {
            if(mp[mod[i-1]] < j)
            {
                dp[i][j] = max(dp[i][j-mp[mod[i-1]]]+ 1, dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[mp.size()][mp.size()] <<"\n";

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