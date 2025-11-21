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
    string s;
    cin >> s;
    ll n = s.size();
    // cin >> n;
    // read(ent,n);
    map<string, ll> vv = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    vector<pair<ll, ll>> dp(n);

    // string asd;
    dp[0] = {0,1};
    ll mod = 9302023;
    for (ll i = 0; i < n; i++)
    {
        if(i >=1)
        dp[i] = dp[i-1];
        string cur;
        if (i >= 2)
            cur = s.substr(i - 2, 3);
        else continue;
        if (vv.count(cur))
        {
            ll curv,curs;
            ll z = i - cur.size();
            if( z >= 0)
            {
                curv = dp[i - cur.size()].first + cur.size()-1;
                curs = dp[i - cur.size()].second;
            }else{
                curv = cur.size()-1;
                curs = 1;
            }         
            if (curv == dp[i].first)
            {
                dp[i].second=  (dp[i].second + dp[i - cur.size()].second)%mod;
            }
            else
            {
                dp[i] = max(dp[i], {curv, curs});
            }
        }
        if (i >= 3)
            cur = s.substr(i - 3, 4);
        else continue;
        if (vv.count(cur))
        {
            ll curv,curs;
            ll z = i - cur.size();
            if( z >= 0)
            {
                curv = dp[i - cur.size()].first + cur.size()-1;
                curs = dp[i - cur.size()].second;
            }else{
                curv = cur.size()-1;
                curs = 1;
            }         
            if (curv == dp[i].first)
            {
                dp[i].second=  (dp[i].second + dp[i - cur.size()].second)%mod;
            }
            else
            {
                dp[i] = max(dp[i], {curv, curs});
            }
        }
        if (i >= 4)
            cur = s.substr(i - 4, 5);
        else continue;
        if (vv.count(cur))
        {
            ll curv,curs;
            ll z = i - cur.size();
            if( z >= 0)
            {
                curv = dp[i - cur.size()].first + cur.size()-1;
                curs = dp[i - cur.size()].second;
            }else{
                curv = cur.size()-1;
                curs = 1;
            }         
            if (curv == dp[i].first)
            {
                dp[i].second=  (dp[i].second + dp[i - cur.size()].second)%mod;
            }
            else
            {
                dp[i] = max(dp[i], {curv, curs});
            }
        }
    }
    cout << s.length() - dp[n-1].first << "\n" << dp[n-1].second << "\n";
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