#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Segment Tree with lazy range-add to "count[u]" and tracking
// sumW = sum of Δw over the segment
// sumWC = sum of Δw * count[u] over the segment
struct SegmentTree {
    int n;
    vector<ll> sumW, sumWC, lazy;
    SegmentTree(int _n): n(_n) {
        sumW.assign(4*n, 0);
        sumWC.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
    // build from base[] where base[pos[u]] = Δw[u]
    void build(int id, int l, int r, const vector<ll>& base) {
        if (l == r) {
            sumW[id] = base[l];
            sumWC[id] = 0;
            lazy[id] = 0;
        } else {
            int mid = (l + r) >> 1;
            build(id<<1,     l,   mid, base);
            build(id<<1|1, mid+1,   r,   base);
            sumW[id] = sumW[id<<1] + sumW[id<<1|1];
            sumWC[id] = 0;
            lazy[id] = 0;
        }
    }
    // push lazy down
    void push(int id) {
        if (lazy[id] != 0) {
            ll v = lazy[id];
            int L = id<<1, R = id<<1|1;
            lazy[L] += v;
            sumWC[L] += v * sumW[L];
            lazy[R] += v;
            sumWC[R] += v * sumW[R];
            lazy[id] = 0;
        }
    }
    // range-add "val" to count[u] for u in [ql..qr] in the base array
    void update(int id, int l, int r, int ql, int qr, ll val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[id]   += val;
            sumWC[id]  += val * sumW[id];
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        update(id<<1,   l,   mid, ql, qr, val);
        update(id<<1|1, mid+1, r,   ql, qr, val);
        sumWC[id] = sumWC[id<<1] + sumWC[id<<1|1];
    }
    // range-sum of Δw[u]*count[u] over [ql..qr]
    ll query(int id, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return sumWC[id];
        push(id);
        int mid = (l + r) >> 1;
        return query(id<<1,   l,   mid, ql, qr)
             + query(id<<1|1, mid+1, r,   ql, qr);
    }
};

// --- Heavy-Light Decomposition ---
int n;
vector<vector<int>> adj;
vector<int> parent_, depth, heavy, head, pos, sz;
int curPos;

// first DFS: compute sz[u] and heavy child
int dfs1(int u) {
    sz[u] = 1;
    int maxSub = 0;
    heavy[u] = -1;
    for (int v : adj[u]) {
        depth[v] = depth[u] + 1;
        dfs1(v);
        if (sz[v] > maxSub) {
            maxSub = sz[v];
            heavy[u] = v;
        }
        sz[u] += sz[v];
    }
    return sz[u];
}

// second DFS: assign head[u] and pos[u]
void dfs2(int u, int h) {
    head[u] = h;
    pos[u]  = curPos++;
    if (heavy[u] != -1)
        dfs2(heavy[u], h);
    for (int v : adj[u]) {
        if (v == heavy[u]) continue;
        dfs2(v, v);
    }
}

// update +1 on path u->v (here v will always be 1)
void path_update(int u, int v, SegmentTree &st) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        st.update(1, 0, n-1, pos[head[u]], pos[u], 1);
        u = parent_[head[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    st.update(1, 0, n-1, pos[v], pos[u], 1);
}

// query sum Δw[u]*count[u] on path u->v
ll path_query(int u, int v, SegmentTree &st) {
    ll res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        res += st.query(1, 0, n-1, pos[head[u]], pos[u]);
        u = parent_[head[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    res += st.query(1, 0, n-1, pos[v], pos[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // multiple test cases until EOF
    while ( (cin >> n) ) {
        vector<ll> w(n+1);
        for (int i = 1; i <= n; ++i) 
            cin >> w[i];

        parent_.assign(n+1, 0);
        for (int i = 2; i <= n; ++i)
            cin >> parent_[i];

        // build tree
        adj.assign(n+1, {});
        for (int i = 2; i <= n; ++i)
            adj[parent_[i]].push_back(i);

        // compute Δw[u]
        vector<ll> deltaW(n+1);
        deltaW[1] = 0;
        for (int i = 2; i <= n; ++i)
            deltaW[i] = w[i] - w[parent_[i]];

        // HLD setup
        depth.assign(n+1,0);
        sz.assign(n+1,0);
        heavy.assign(n+1,-1);
        dfs1(1);
        head.assign(n+1,0);
        pos .assign(n+1,0);
        curPos = 0;
        dfs2(1,1);

        // base array for segment tree: base[pos[u]] = deltaW[u]
        vector<ll> base(n);
        for (int u = 1; u <= n; ++u)
            base[pos[u]] = deltaW[u];

        // build segment tree
        SegmentTree st(n);
        st.build(1,0,n-1, base);

        // compute f(i) on the fly
        vector<ll> f(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i > 1) {
                // f(i) = (i-1)*w[1] + sum_{u∈path(i->1)} deltaW[u] * count[u]
                ll term1 = (ll)(i-1) * w[1];
                ll S     = path_query(i,1,st);
                f[i] = term1 + S;
            }
            // now mark node i as processed: increment count[u] on path(i->1)
            path_update(i,1,st);
        }

        // output f(2..n)
        for (int i = 2; i <= n; ++i) {
            cout << f[i] << '\n';
        }
    }

    return 0;
}
