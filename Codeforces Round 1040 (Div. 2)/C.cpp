#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define int ll
struct LazySegTree
{
    ll n;
    vector<long long> tree, lazy;

    LazySegTree(int size)
    {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(vector<int> &arr, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = arr[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void build(vector<int> &arr)
    {
        build(arr, 1, 0, n - 1);
    }

    void push(int v, int tl, int tr)
    {
        if (lazy[v] != 0)
        {
            int tm = (tl + tr) / 2;

            tree[v * 2] += tm-tl + 1;
            lazy[v * 2] += lazy[v];

            tree[v * 2 + 1] += tr-tm;
            lazy[v * 2 + 1] += lazy[v];

            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, long long addend)
    {
        if (lazy[v] != 0)
        {
            // tree[v] = tr - tl+1;
            push(v, tl, tr);
        }
        if (l > r)
            return;

        if (l == tl && r == tr)
        {
            ll k = (r - l + 1);
            tree[v] =(tr - tl + 1);
            lazy[v] =1;
        }
        else
        {
            if (lazy[v] != 0)
            {
                tree[v] = tr - tl+1;
                push(v, tl, tr);
            }
            // push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            ll k = tree[v * 2] + tree[v * 2 + 1];
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
            
        }
    }

    void update(int l, int r, long long addend)
    {
        update(1, 0, n - 1, l, r, addend);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if(lazy[v] != 0)
        {
            return r-l+1;
        }
        if (l == tl && r == tr)
            return tree[v];
        
        
        int tm = (tl + tr) / 2;

        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    long long query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
/*
1 2 
1 3 
2 5 
1 4
2 6
2 3
1 6
6
*/
/*
7
1 2
1 3
2 5
1 4
2 6
2 3
1 6
*/
ll m = 0;
void Solve()
{
    ll n;
    cin >> n;
    vector<ll> tree(4 * n * 2 + 20), lazy(4 * n * 2 + 20);
    // vector<long>comp(n),H(n);
    vector<pair<ll, ll>> ent(n);
    for (auto &e : ent)
    {
        ll a, b;
        cin >> a >> b;
        e = {a, b};
    }
    set<ll> ex;
        LazySegTree st(2 * n + 20);
    if(m==405)
    {
        cout << n;
        for(auto e : ent)
        {
            cout << e.first << e.second;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll z = st.query(1, 1, 2 * n + 1, ent[i].first, ent[i].second);
        ll l=ent[i].first ,r=ent[i].second;
        if (z != (ent[i].second - ent[i].first + 1))
        {
            st.update(1, 1, 2 * n + 1, ent[i].first, ent[i].second, 0);
            z = st.query(1, 1, 2 * n + 1, ent[i].first, ent[i].second);
            z+=2;
        }
        else
            ex.insert(i);
    }
    cout << n-ex.size() << "\n";
    for (int i = 0; i < n; i++)
    {
        if (ex.find(i) == ex.end())
        {
            cout << i+1<< " ";
        }
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    
    while (tt--)
    {
        m++;
        
        Solve();
    }
}
/*
    1 - 1
    2
*/