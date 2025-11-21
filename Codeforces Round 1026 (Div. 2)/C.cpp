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
    int n;
    cin >> n;
    read(ent, n);
    vector<pair<ll, ll>> obs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> obs[i].first >> obs[i].second;
    }
    ll cur = 0, mx = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        if (ent[i] != -1)
        {
            dp[i + 1][0] = dp[i][0] + ent[i];
            dp[i + 1][1] = min(dp[i][1] + ent[i], obs[i].second);
        }
        else
        {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = min(dp[i][1] + 1, obs[i].second);
        }
        if (dp[i + 1][1] >= obs[i].first)
        {
            dp[i + 1][0] = max(dp[i + 1][0], obs[i].first);
        }
        else
        {
            cout << "-1\n";
            return;
        }
        if(dp[i + 1][0] > obs[i].second)
        {
            cout << "-1\n";
            return;
        }
    }
    ll ini = dp[n][0];
    vector<ll> ans(n );
    for(int i =n;i > 0;i--)
    {
        if(ent[i-1] == -1)
        {
            if(dp[i-1][0] < ini){
                ent[i-1] = 1;
                ini--;
            }
            else{
                ent[i-1] = 0;
            }

        }else ini-= ent[i-1];  
    }
    for(int i = 0;i < n;i++)
    {
        cout << ent[i] << " ";
    }
    cout << "\n";
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