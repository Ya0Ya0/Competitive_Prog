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
void Solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> f(n);
    map<ll, ll> mp;
    vector<ll> nw;
    for (auto &e : f)
    {
        cin >> e;
    }
    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        mp[f[i]] = t;
    }
    sort(all(f));
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < n ; i++)
    {
        
        ll pos = max(m - mp[f[i]] * f[i], m % f[i]);
        ll used1 = (m - pos) / f[i];
        if (i == n-1 || f[i + 1] - f[i] > 1)
        {
            ans = max(ans, m - pos);
            continue;
        }
        ll pos2 = max(pos - mp[f[i + 1]] * f[i + 1], pos % f[i + 1]);
        ll used2 = (pos - pos2) / f[i + 1];
        ans = max(ans, m - pos2);
        if(mp[f[i+1]] > used2 && pos2 > 0)
        {
            ll pos_best = min(mp[f[i+1]] - used2, pos2);
            ll imp = min(used1, pos_best);
            pos2-=imp;
            ans = max(ans,m-pos2);
        }
    }
    cout << ans << '\n';
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