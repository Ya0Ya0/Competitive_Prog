#pragma GCC optimize("O3,unroll-loops")
 
#include <bits/stdc++.h>
 
#define endl '\n'
 
using namespace std;
 
typedef pair<int, int> ipair;
 
#define INF 1'000'000'009
#define MAXN 200200
#define MAXMEM 5'000'000
#define MAXLEN 2'000'100
 
#define X first
#define Y second
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct node {
    node *lv = nullptr, *rv = nullptr;
    ipair key;
    int prior;
    int minl = INF;
    
    node(const ipair& key) : key(key), prior(rng()), minl(key.Y) {}
};
 
static inline int minl(node *v) {
    return (v == nullptr ? INF : v->minl);
}
 
static inline void upd(node *v) {
    v->minl = min(v->key.Y, min(minl(v->lv), minl(v->rv)));
}
 
node *merge(node *s1, node *s2) {
    if (s1 == nullptr) return s2;
    if (s2 == nullptr) return s1;
    if (s1->prior > s2->prior) {
        s1->rv = merge(s1->rv, s2);
        upd(s1);
        return s1;
    } else {
        s2->lv = merge(s1, s2->lv);
        upd(s2);
        return s2;
    }
}
 
pair<node*, node*> split(node* &v, ipair x) {
    if (v == nullptr) {
        return {nullptr, nullptr};
    }
    if (v->key < x) {
        auto [s1, s2] = split(v->rv, x);
        v->rv = s1;
        upd(v);
        return {v, s2};
    } else {
        auto [s1, s2] = split(v->lv, x);
        v->lv = s2;
        upd(v);
        return {s1, v};
    }
}
 
int n, m;
int arr[MAXN];
node *mem = (node*)calloc(MAXMEM, sizeof(*mem));
node *mpos = mem;
node *root;
set<int> M;
 
// [l..r)
void add_seg(int l, int r) {
    if (l >= r) return;
    ipair p {r - l, l};
    auto [s1, s2] = split(root, p);
    node *v = mpos++;
    *v = node(p);
    root = merge(merge(s1, v), s2);
}
 
void rem_dek(node* &v, const ipair& x) {
    if (v == nullptr) return;
    if (v->key == x) {
        v = merge(v->lv, v->rv);
        if (v) upd(v);
        return;
    }
    if (v->key < x) rem_dek(v->rv, x);
    else rem_dek(v->lv, x);
    upd(v);
}
 
// [l..r)
void rem_seg(int l, int r) {
    if (l >= r) return;
    ipair p {r - l, l};
    rem_dek(root, p);
}
 
void add_val(int x) {
    auto it = M.lower_bound(x);
    int clsl = (it == M.begin() ? 0 : *prev(it));
    int clsr = (it == M.end() ? INF : *it);
    rem_seg(clsl + 1, clsr);
    add_seg(clsl + 1, x);
    if (clsr != INF) add_seg(x + 1, clsr);
    M.insert(x);
}
 
void rem_val(int x) {
    auto it = M.lower_bound(x);
    int clsl = (it == M.begin() ? 0 : *prev(it));
    int clsr = (next(it) == M.end() ? INF : *next(it));
    rem_seg(clsl + 1, x);
    rem_seg(x + 1, clsr);
    if (clsr != INF) add_seg(clsl + 1, clsr);
    M.erase(x);
}
 
int query(int k) {
    if (M.empty()) return 1;
    auto [s1, s2] = split(root, make_pair(k, -1));
    fprintf(stderr, "AMOGUS: %p, %p\n", s1, s2);
    int ans = min(*M.rbegin() + 1, minl(s2));
    root = merge(s1, s2);
    return ans;
}
 
void init() {
    root = nullptr;
    mpos = mem;
    M = {arr, arr + n};
    add_seg(1, *M.begin());
    for (auto it = M.begin(); next(it) != M.end(); ++it)
        add_seg(*it + 1, *next(it));
}
 
signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        init();
        cin >> m;
        for (int j = 0; j < m; ++j) {
            char tp; cin >> tp;
            int x, k;
            switch (tp) {
            case '+':
                cin >> x;
                add_val(x);
                break;
            case '-':
                cin >> x;
                rem_val(x);
                break;
            case '?':
                cin >> k;
                cout << query(k) << " ";
                break;
            }
        }
        cout << endl;
    }
}