#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n, t[4*MAXN];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] =max(t[v*2],t[v*2+1]);
    }
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] =max(t[v*2],t[v*2+1]);
    }
}
ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2, tl, tm, l, min(r, tm))
           , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void Solve()
{
    cin >> n;
    vector<long> tree(4*n);
    vector<long>comp(n),H(n);
    vector<long> ent(n);
    for(auto &e: ent)
    {
        cin >> e;
    }
    //build(tree,ent,1,0,n-1);
    for(int i = 0; i < n; i++)
    {
        update(tree,1,max(0L,i-ent[i]),min(n-1,i+ent[i]),0,n-1);
    }
    for(int i = 0; i < n; i++)
    {
        comp[i] = get(tree,1,0,n-1,i);
    }
    sort(comp.begin(),comp.end());
    for(auto &h : H)
    {
        cin >> h;
    }
    
    sort(H.begin(),H.end());
    for(int i = 0; i < n; i++)
    {
        if(H[i]!=comp[i])
        {
            cout << "NO\n";return;
        } 
    }
    cout << "YES\n";


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