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
    vector<pair<ll, ll>> ent(n);
    vector<ll> metal(m);
    for (auto &e : ent)
    {
        cin >> e.second;
    }
    for (auto &e : ent)
    {
        ll t;
        cin >> t;
        e.first = e.second - t;
    }
    ll ans = 0;
    sort(all(ent));
    map<ll, ll> map;

    vector<pair<ll, ll>> vs;
    vs.push_back(ent.front());
    for (int i = 1; i < n; i++)
    {
        if (ent[i].second >= vs.back().second)
            continue;
        if (vs.size() && vs.back().second > ent[i].second && vs.back().first == ent[i].first)
        {
            vs.back() = ent[i];
            continue;
        }        
        vs.push_back(ent[i]);
    }
    ent = vs;
    ll maxi = 3000020;
    vector<ll> dp(maxi);
    for (ll i = 1, j = vs.size() - 1; i <= maxi; i++)
    {
        while (vs[j].second <= i && j >= 0)
            j--;
        if (j < ((ll)vs.size() - 1))
            dp[i] = dp[i - vs[j + 1].first] + 1;
    }

    for (auto e : metal)
    {
        cin >> e;
        if (e > ent[0].second)
        {
            ll temp = (e - ent[0].second+ent[0].first-1) / ent[0].first;
            e -= temp*ent[0].first;
            ans +=temp;
        }
        ans += dp[e];
    }
    cout << ans * 2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}