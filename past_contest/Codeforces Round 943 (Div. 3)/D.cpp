#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    long long n,k,p1,p2;
    cin >> n >> k >> p1 >> p2;
    vector<int>p(n),a(n);
    for(auto &P:p)cin >> P;
    for(auto &A:a)cin >> A;
    vector<bool>vis(n);
    long long ans=0,ans2=0, ite=0,temp=0;
    while(!vis[p1])
    {     
        if(ite>k)break;
        vis[p1]=true;   
        ans=max(ans,(a[p1-1]*(k-ite))+temp);
        temp+=a[p1-1];
        p1 = p[p1-1];
        ite++;
    }
    vis.assign(n,false);
    ite=0,temp=0;
    while(!vis[p2])
    {       
        if(ite>k)break; 
        vis[p2]=true; 
        ans2=max(ans2,a[p2-1]*(k-ite)+temp);
        temp+=a[p2-1];
        p2 = p[p2-1];
        ite++;
    }
    cout << (ans>ans2?"Bodya\n":ans==ans2?"Draw\n":"Sasha\n");
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}