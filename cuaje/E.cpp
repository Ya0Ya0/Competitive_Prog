#include <bits/stdc++.h>
using namespace std;

long long aux(long long sum,long long cur,long long j,vector<long long >&memo,vector<long long>&ent,long long s)
{
    long long ans = 0;
    if(j == memo.size())return 0;
    string s;
    
    if(sum+ent[j] > s && memo[j])
    {
        return memo[j];
    }
    else if(sum+ent[j] > s){
        memo[j] = aux(ent[j],cur+1,j+1,memo,ent,s);
        return memo[j]+cur+1;
        
    }
    else{
        return aux(sum+ent[j],cur,j+1,memo,ent,s)+cur;
    }  
}
// for(long long i = 0; i < n;i++)
//     {
//         long long sum=0;
//         long long cur = 1;
//         for(long long j = i ;j  <n; j++)
//         {
//             sum+=ent[j];
//             if(sum>s)
//             {
//                 sum = ent[j];
//                 cur++;
//             }            
//             ans+=cur;
//         }
      /*
      long long sum=0;
        long long cur = 1;
        ans += aux(sum,cur,i,memo,ent,s);
        */  
//  89 173  256 }
void Solve()
{
    long long n,s;cin >> n >> s;
    vector<long long>ent(n);
    vector<long long>memo(n);
    for(auto &e :ent)cin >>e;
    long long ans = 0;
    for(long long i = 0; i < n;i++)
    {
        
    
        long long sum=0;
        long long cur = 1;
        ans += aux(sum,cur,i,memo,ent,s);
        
    }
    cout <<ans;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}
