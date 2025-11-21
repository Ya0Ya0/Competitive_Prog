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
ll mx = 2 * 1e5 + 5;
int t=0;
vector<vector<ll>> g(mx);
vector<ll> f(mx);
void Solve()
{
    ll n, m;
    cin >> n >> m;
    
    ll btt0 = -1;
    ll mex1 = -1, mex2 = -1, minn = -1, maxn = -1;
    vector<pair<ll,ll>>ed;
    for (int j = 0; j < n; j++)
    {
        ll sz;
        cin >> sz;
        map<ll, ll> tt;
        for (int k = 0; k < sz; k++)
        {
            ll e;
            cin >> e;
            tt[e]++;
        }
        mex1 = -1, mex2 = -1;
        for (ll i = 0; i < mx; i++)
        {
            if (!tt[i] && mex1 == -1)
            {
                mex1 = i;
            }
            else if (!tt[i] && mex1 != -1)
            {
                mex2 = i;
                break;
            }
        }
        minn = max(minn, mex1);
        maxn = max(maxn, mex2);
        btt0 = max(btt0, mex1);
        ed.push_back({mex1,mex2});
    }
    ll sans = 0;
    for(int i =0; i < maxn+3;i++)
    {
        g[i].clear();
        f[i] = 0;
    }
    for(auto e : ed)
    {
        g[e.first].push_back(e.second);
    }
    for (ll i = maxn; i >= 0; i--)
    {
        f[i] = max(i, minn);
        for (auto e : g[i])
        {
            f[i] = max(f[e], f[i]);
        }
        if (g[i].size() >= 2)
        {
            minn = max(minn,f[i]);
        }
    }
    for (ll i = min(m, maxn); i >= 0; i--)
        sans += max(minn,f[i]);
    ll l = maxn * (maxn + 1) / 2;
    ll r = m * (m + 1) / 2;
    if (m - maxn > 0)
        sans += r - l;
    cout << sans << "\n";
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
        t++;
    }
}