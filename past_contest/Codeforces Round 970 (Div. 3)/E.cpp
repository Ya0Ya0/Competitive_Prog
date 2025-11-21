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
// const ll MX = 2 * 1e5 + 5;
const ll MX = 10;
ll dp[2][MX];
void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[0][0] = dp[0][0] = dp[1][1] = dp[1][0] = 0;
    map<char, ll> even, odd;
    ll mx[2]{1,1};
    char mxc[2];
    for (int i = 0; i < n; i++)
    {
        if (i == 2)
            break;
        if (!(i & 1))
        {
            even[s[i]]++;
            mxc[0] = s[i];
        }
        else
        {
            odd[s[i]]++;
            mxc[1] = s[i];
        }
    }

    for (int i = 2; i < n; i++)
    {
        ll z= 0;
        if (!(i & 1))
        {
            z = ++even[s[i]];
        }
        else
        {
            z = ++odd[s[i]];
        }
        if(z > mx[(i&1)])
        {
            mx[i&1] = z;
            mxc[i&1] = s[i];
        }
        auto &cur =  i&1?odd : even;
        dp[0][i] = (i)/2+1 - mx[i&1] + (i+1)/2 - mx[!(i&1)];
        ll b = (s[i] != mxc[!(i&1)]);
        dp[1][i] = min(dp[0][i-1] + 1, dp[1][i-1] + b);
    }
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