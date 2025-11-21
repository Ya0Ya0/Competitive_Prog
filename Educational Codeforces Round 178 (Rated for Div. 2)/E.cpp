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
#define MAXN 30
int t[4 * MAXN];
// void build(vector<pair<ll, ll>> &a, ll v, ll tl, ll tr)
// {
//     if (tl == tr)
//     {
//         t[v] = a[tl].first;
//     }
//     else
//     {
//         ll tm = (tl + tr) / 2;
//         build(a, v * 2, tl, tm);
//         build(a, v * 2 + 1, tm + 1, tr);
//         t[v] = max(t[v * 2], t[v * 2 + 1]);
//     }
// }
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
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
ll minn(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return min(minn(v * 2, tl, tm, l, min(r, tm)), minn(v * 2 + 1, tm + 1, tr, min(l, tm + 1), r));
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    // read(ent,n);

    vector<ll> cnt(k + 1);
    vector<ll> lft(n+1),lst(k+1);
    string s;
    cin >> s;
    for (ll i = n - 1; i >= 0; i--)
    {
         
        ll cur = LONG_LONG_MAX;
        for (int j = 0; j < k; j++)
        {
            // if(j!=s[i] - 'a')
            cur = min(cur,lft[lst[j]]+1);
        }
        lst[s[i] - 'a'] = i;
        lft[i] = cur;
        cnt[s[i] - 'a']++;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        string z;
        cin >> z;
        ll idx = 0, iddx = 0;
        bool ok = false;
        for (auto c : s)
        {

            if (c == z[idx])
                idx++;
            if (idx == z.size())
            {
                ok = true;
                break;
            }
            iddx++;
        }
        if (!ok)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << lft[iddx] << "\n";
    }
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