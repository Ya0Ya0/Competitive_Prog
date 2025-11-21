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
#define MAXN 100005
int t[4 * MAXN];
void build(vector<pair<ll, ll>> &a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl].first;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
ll mxx(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return max(mxx(v * 2, tl, tm, l, min(r, tm)), mxx(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
ll c = 5001;
void Solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ent(n);
    vector<ll> pre(n + 1), dp(n);
    for (auto &[a, b] : ent)
    {
        cin >> a >> b;
    }

    deque<pair<ll, ll>> q;
    vector<ll> lst(n + 1, -1);
    for (ll i = 0; i < n; i++)
    {

        auto z = ent[i];
        ll mx = 0;
        while (!q.empty() && (q.back().first <= z.first || q.back().second == z.second))
        {
            if (q.back().second == z.second)
            {
                auto cur = q.back();
                q.pop_back();
                z.first = cur.first + z.first - mx;
                mx = 0;
                continue;
            }
            mx = max(mx, q.back().first);
            q.pop_back();
        }
        q.push_back(z);

        dp[i] = q.front().first;
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";
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