#include"bits/stdc++.h"
using namespace std;
void build(vector<long>& tree,vector<long>& ent,int v,int l ,int r)
{
    if(l == r)
    {
        tree[v] = ent[l];
    }
    else{
        int mid = (l+r)/2;
        build(tree,ent,v*2,mid+1,r);
        build(tree,ent,v*2+1,l,mid);
        tree[v] = 0;
    }
}
void update(vector<long>& tree,int v,int l ,int r,int segL,int segR)
{
    if(l > r)
        return;
    if(l == segL && r == segR)
         tree[v]++;
    else
    {
        int mid = (segL+segR)/2;
        update(tree,v*2,l,min(r,mid),segL,mid);
        update(tree,v*2+1,max(mid+1,l),r,mid+1,segR);
    }   
}
long get(vector<long>& tree,int v,int l ,int r,int pos)
{
    if(l == r)
        return tree[v];
    int mid = (l+r)/2;
    int sum=0;
    if(pos <= mid )
       sum= tree[v] + get(tree,v*2,l,mid,pos);
    else
        sum= tree[v] + get(tree,v*2+1,mid+1,r,pos);
    return sum;
}

void Solve()
{
    long n;cin >> n;
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