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
ll mod = 998244353;
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = r * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return r;
}
void init() {};
const ll MAXN = 3 * 1e5;
ll t[4*MAXN];
void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = 0;
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        t[v] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int get(int v, int tl, int tr, int pos)
{
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v * 2, tl, tm, pos);
    else
        return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}
void Solve()
{
    int n;
    cin >> n;
    read(ent, n);
    // reverse(all(ent));
    map<ll, ll> f, b;
    vector<ll> vf, vb;
    for (ll pr = 0, i = 0; i < n; i++)
    {
        if (ent[i] > pr)
        {
            pr = ent[i];
            f[ent[i]] = 1;
            vf.push_back(ent[i]);
        }
    }
    for (ll pr = 0, i = n - 1; i >= 0; i--)
    {
        if (ent[i] > pr)
        {
            pr = ent[i];
            b[(ent[i])] = 1;
            vb.push_back(ent[i]);
        }
    }

    map<ll, ll> seen, ff;
    // map<ll, ll> inc;
    vector<ll> lef(n);
    build(0, 0, n - 1);
    for (int i = 0; i < n; i++)
    {

        ll z = lower_bound(all(vf), ent[i]) - vf.begin();
        update(1, 0, n - 1, z, n - 1, 1);
        if (f.count(ent[i]))
        {
            if (z > 0)
            {
                ff[ent[i]] = ff[ent[i]] * elevar(2, get(1, 0, n - 1, z)) % mod;
                update(1, 0, n - 1, z, z, -get(1, 0, n - 1, z));
                ff[vf[z - 1]] = ff[vf[z - 1]] * elevar(2, get(1, 0, n - 1, z - 1)) % mod;
                update(1, 0, n - 1, z-1, z-1, -get(1, 0, n - 1, z-1));
                ff[ent[i]] = (ff[ent[i]] + ff[vf[z - 1]]) % mod;
            }
            else
            {
                ff[ent[i]] = ff[ent[i]] * elevar(2, get(1, 0, n - 1, z)) % mod;
                update(1, 0, n - 1, z, z, -get(1, 0, n - 1, z));
                ff[ent[i]] = (ff[ent[i]] % mod + 1) % mod;
            }
            if (z < vf.size() - 1)
            {
                // ff[vf[z + 1]] = ff[vf[z + 1]] * elevar(2, get(1, 0, n - 1, z)) % mod;
                // update(1, 0, n - 1, z + 1, z + 1, -get(1, 0, n - 1, z + 1));
                // ff[vf[z + 1]] = (ff[vf[z + 1]] + ff[ent[i]]) % mod;
            }
            else
            {
                if (z == 0)
                    lef[i] = 1;
                else
                    lef[i] = ff[vf[z - 1]];
            }
        }

        // seen[ent[i]]++;
    }
    build(0, 0, n - 1);
    vf = vb;
    ll ans = 0;
    f = b;
    ff.clear();
    seen.clear();
    ll lf = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll z = lower_bound(all(vf), ent[i]) - vf.begin();
        update(1, 0, n - 1, z, n - 1, 1);
        if(ent[i]!=vf.back())
        lf = (lf * 2) % mod;
        if (f.count(ent[i]))
        {
            if (z > 0)
            {
                ff[ent[i]] = ff[ent[i]] * elevar(2, get(1, 0, n - 1, z)) % mod;
                update(1, 0, n - 1, z, z, -get(1, 0, n - 1, z));
                ff[vf[z - 1]] = ff[vf[z - 1]] * elevar(2, get(1, 0, n - 1, z - 1)) % mod;
                update(1, 0, n - 1, z-1, z-1, -get(1, 0, n - 1, z-1));
                ff[ent[i]] = (ff[ent[i]] + ff[vf[z - 1]]) % mod;
            }
            else
            {
                ff[ent[i]] = ff[ent[i]] * elevar(2, get(1, 0, n - 1, z)) % mod;
                update(1, 0, n - 1, z, z, -get(1, 0, n - 1, z));
                ff[ent[i]] = (ff[ent[i]] % mod + 1) % mod;
            }
            if (z < vf.size() - 1)
            {
                // ff[vf[z + 1]] = ff[vf[z + 1]] * elevar(2, get(1, 0, n - 1, z)) % mod;
                // update(1, 0, n - 1, z + 1, z + 1, -get(1, 0, n - 1, z + 1));
                // ff[vf[z + 1]] = (ff[vf[z + 1]] + ff[ent[i]]) % mod;
            }
            else
            {
                ll p;
                if (z == 0)
                    p = 1;
                else
                    p = ff[vf[z - 1]];
                ans = (ans + (lf+p) * lef[i]) % mod;
                lf = (lf * 2) % mod;
                lf += p;
                
            }
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
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}