#include "bits/stdc++.h"
using namespace std;
#define MAXN 100005
#define ll long long
template <class T> struct fenwick_tree {
    

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += T(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};


void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>ent(m);
    for(int i =0; i < m;i++)
    {
        cin >> ent[i];
    }
    fenwick_tree<ll> a(m),b(m);
    for(int i =0; i <m;i++)
    {
        if(ent[i] == 1 )
        {
            a.add(i,1);
        }
        if(ent[i] == 2 )
        {
            b.add(i,1);
        }
    }
    vector<ll>ans(m);
    ll cura =0,curb =0;
    for(int i =0;i < m;i++)
    {
        if(ent[i] == 1 )
        {
            cura+=i;
        }
        if(ent[i] == 2 )
        {
            curb+=i;
        }
    }
    ans[0] = abs(cura - curb);
    for(int i =1;i <m;i++)
    {
        cura += a.sum(0,i);
        cura -= a.sum(i,m);
        curb += b.sum(0,i);
        curb -= b.sum(i,m);
        ans[i] = abs(cura-curb);
    }
    for(auto a : ans)
    {
        cout << a << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}
/*
    1 - 1
    2
*/