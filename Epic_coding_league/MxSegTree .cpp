#include"bits/stdc++.h"
using namespace std;
#define MAXN 100005
#define ll long long
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

void Solve()
{    


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