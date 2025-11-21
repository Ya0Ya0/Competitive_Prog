#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
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


const int MAXN = 2e5;
const int MAXLOG = 18;
 
int n;
vector<int> g[MAXN];
int sz[MAXN];
int tin[MAXN];
int par[MAXN];
int rt[MAXN];
int pre[MAXN][MAXLOG];
int segtree[4 * MAXN];
 
void upd(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        segtree[v] = x;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        upd(2 * v, tl, tm, pos, x);
    }
    else {
        upd(2 * v + 1, tm + 1, tr, pos, x);
    }
    segtree[v] = max(segtree[2 * v], segtree[2 * v + 1]);
}
 
int get(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) {
        return -1;
    }
    if (l <= tl && tr <= r) {
        return segtree[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
 
int timer = 0;
 
void dfs(int vertex, int parent = -1) {
    sz[vertex] = 1;
    int posnow = -1, posmax = 0;
    for (int posnow = 0; posnow < g[vertex].size(); posnow++) {
        int son = g[vertex][posnow];
        if (son != parent) {
	        dfs(son, vertex);
	        if (sz[son] > sz[g[vertex][posmax]]) {
	            posmax = posnow;
	        }
	        sz[vertex] += sz[son];
        }
    }
    if(g[vertex].size())
    swap(g[vertex][0], g[vertex][posmax]);
}
 
void calc(int v, int p = 0, int root = -1) {
    tin[v] = timer++;
    pre[v][0] = p;
    for (int i = 1; i < MAXLOG; i++) {
        pre[v][i] = pre[pre[v][i - 1]][i - 1];
    }
    if (root == -1) {
        root = v;
    }
    rt[v] = root;
    int alr = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        if (!alr) {
            calc(to, v, root);
            alr = 1;
        }
        else {
            calc(to, v);
        }
    }
}
 
int isp(int a, int b) {
    return tin[a] <= tin[b] && tin[b] <= tin[a] + sz[a] - 1;
}
 
int lca(int a, int b) {
    if (isp(a, b)) {
        return a;
    }
    if (isp(b, a)) {
        return b;
    }
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (!isp(pre[a][i], b)) {
            a = pre[a][i];
        }
    }
    return pre[a][0];
}
 
inline void init() {
 
}
 
inline void solve() {
    init();
    cin >> n;
    vector<ll>tw(n);
    for(auto &t : tw)cin >> t;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    calc(0);
    for (int i = 0; i < n; i++) {
        upd(1, 0, MAXN - 1, tin[i], tw[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == '!') {
            int a, b;
            cin >> a >> b;
            a--;
            upd(1, 0, MAXN - 1, tin[a], b);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int w = lca(l, r);
            int ans = 0;
            while (!isp(rt[l], w)) {
                ans = max(ans, get(1, 0, MAXN - 1, tin[rt[l]], tin[l]));
                l = pre[rt[l]][0];
            }
            ans = max(ans, get(1, 0, MAXN - 1, tin[w], tin[l]));
            while (!isp(rt[r], w)) {;
                ans = max(ans, get(1, 0, MAXN - 1, tin[rt[r]], tin[r]));
                r = pre[rt[r]][0];
            }
            ans = max(ans, get(1, 0, MAXN - 1, tin[w], tin[r]));
            cout << ans << '\n';
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // while (cin >> n) {
    solve();
	// }
    return 0;
}