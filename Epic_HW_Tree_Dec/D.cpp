#include "bits/stdc++.h"
using namespace std;
#define int long long
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

const int MAXN = 2e5+5;
const int MAXLOG = 18;

int n;
vector<int> g[MAXN];
int sz[MAXN];
int tin[MAXN];
int tin_p[MAXN];
int par[MAXN];
int rt[MAXN];
int pre[MAXN][MAXLOG];
int segtree[4 * MAXN];
int segtree_w[4 * MAXN];
int lazy[4 * MAXN];

int w_d[MAXN];
int tw[MAXN];
ll ans[MAXN];

void push(int v)
{
    int cnt = lazy[v];
    lazy[v] = 0;

    lazy[v * 2] += cnt;
    lazy[v * 2 + 1] += cnt;

    segtree[v * 2] += segtree_w[v * 2] * cnt;
    segtree[v * 2 + 1] += segtree_w[v * 2 + 1] * cnt;
}

void upd(int v, int tl, int tr, int range_l, int range_r, int x)
{
    if (tr < range_l || tl > range_r)
        return;
    if (tl >= range_l && tr <= range_r)
    {
        segtree[v] += segtree_w[v];
        lazy[v] += x;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    upd(2 * v, tl, tm, range_l, range_r, x);
    upd(2 * v + 1, tm + 1, tr, range_l, range_r, x);

    segtree[v] = (segtree[2 * v] + segtree[2 * v + 1]);
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        segtree_w[v] = w_d[tin_p[tl]];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    segtree_w[v] = segtree_w[v * 2] + segtree_w[v * 2 + 1];
    segtree[v] = 0;
    lazy[v] = 0;
}
void dbuild(int v, int tl, int tr)
{
    if (tl == tr)
    {
        segtree_w[v] = 0;
        segtree[v] = 0;
        lazy[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    dbuild(v * 2, tl, tm);
    dbuild(v * 2 + 1, tm + 1, tr);
    segtree_w[v] = segtree_w[v * 2] + segtree_w[v * 2 + 1];
    segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
    lazy[v] = lazy[v * 2] + lazy[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tl > r || l > tr)
    {
        return 0;
    }
    if (l <= tl && tr <= r)
    {
        return segtree[v];
    }
    int tm = (tl + tr) / 2;
    push(v);
    return (get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r));
}

int timer = 0;

void dfs(int vertex, int parent = -1)
{
    sz[vertex] = 1;
    int posnow = -1, posmax = 0;
    if (parent != -1)
    {
        w_d[vertex] = tw[vertex] - tw[parent];
    }
    for (int posnow = 0; posnow < g[vertex].size(); posnow++)
    {
        int son = g[vertex][posnow];
        if (son != parent)
        {
            dfs(son, vertex);
            if (sz[son] >= sz[g[vertex][posmax]])
            {
                posmax = posnow;
            }
            sz[vertex] += sz[son];
        }
    }
    if (posmax > 0)
        swap(g[vertex][0], g[vertex][posmax]);
}

void calc(int v, int p = 0, int root = -1)
{
    tin[v] = timer++;
    tin_p[tin[v]] = v;
    pre[v][0] = p;
    for (int i = 1; i < MAXLOG; i++)
    {
        pre[v][i] = pre[pre[v][i - 1]][i - 1];
    }
    if (root == -1)
    {
        root = v;
    }
    rt[v] = root;
    int alr = 0;
    for (auto to : g[v])
    {
        if (to == p)
        {
            continue;
        }
        if (!alr)
        {
            calc(to, v, root);
            alr = 1;
        }
        else
        {
            calc(to, v);
        }
    }
}

int isp(int a, int b)
{
    return tin[a] <= tin[b] && tin[b] <= tin[a] + sz[a] - 1;
}

int lca(int a, int b)
{
    if (isp(a, b))
    {
        return a;
    }
    if (isp(b, a))
    {
        return b;
    }
    for (int i = MAXLOG - 1; i >= 0; i--)
    {
        if (!isp(pre[a][i], b))
        {
            a = pre[a][i];
        }
    }
    return pre[a][0];
}

void endit()
{
    for (int i = 0; i < n; i++)
    {
        w_d[i] = 0;
        sz[i] = 0;
        tin[i] = 0;
        tin_p[i] = 0;
        par[i] = 0;
        rt[i] = 0;
        g[i].clear();
        tw[i] = 0;
        ans[i] = 0;
    }
    dbuild(1, 0, n - 1);
    timer = 0;
}

inline void solve()
{
    // init();
    // cin >> n;

    for (int i = 0; i < n; i++)
        cin >> tw[i];
    vector<int>p(n);
    // w_d[0] = tw[0];
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        p[i] = a;
        a--;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    dfs(0);
    calc(0);
    build(1, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     upd(1, 0, MAXN - 1, tin[i], tw[i]);
    // }
    // int m;
    // cin >> m;

    for (int i = 1; i < n; i++)
    {
        int cur = i;
        int cans = 0;
        while (!isp(rt[cur], 0))
        {
            cans += get(1, 0, n - 1, tin[rt[cur]], tin[cur]);
            cur = pre[rt[cur]][0];
        }
        cans += get(1, 0, n - 1, tin[0], tin[cur]);
        ans[i] = cans + tw[0] * (i);

        cur = i;
        // string s;
        // stoll(s);
        while (!isp(rt[cur], 0))
        {
            upd(1, 0, n - 1, tin[rt[cur]], tin[cur], 1);
            cur = pre[rt[cur]][0];
        }
        upd(1, 0, n - 1, tin[0], tin[cur], 1);
        if (i > 0)
        {
            // if (ans[i] == 4859)
            // {
                // string s;
                // for(int i =0;i < n;i++)
                // {
                //     string k = to_string(tw[i]);
                //     int kk = k.size();
                //     cout << kk << k;
                    // s = s + to_string(kk);
                    // s = s +  to_string(tw[i]);
                // }
                // ans[i] =stoll(s);
                // ans[i] = n;
                // for(int i =0;i <n;i++ )
                // {
                //     cout << p[i];
                // }
            //     cout <<"\n";
            // }
            cout << ans[i] << "\n";
        }
    }
    endit();
}
// 13  887 4555 8570 5485 8611 9500 295 2499 83 4959 9772 8620 3825 4  4  1  3  7  12  2  1  9  5  8  12 
// 
// tree 0 4 4 1 3 7 1 2 2 1 9      5 8 1 2
// 3 887 4555 8570 5485 8611 9500 295 2499 83 4959 9772 8620 3825
// tree  4  4  1  3  7  12  2  1  9  5  8  12        
//       2  3  4  5  6   7  8  9  10 11 12 13   
// asdn 3 4 4 4 4 4 3 4 2 4 4 4 4
// w 887 4555 8570 5485 8611 9500 295 2499 83 4959 9772 8620 3825
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n)
    {
        solve();
    }
    return 0;
}