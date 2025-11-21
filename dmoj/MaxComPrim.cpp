#include <bits/stdc++.h>
using namespace std;


void Solve()
{
    int n,k;cin >> n >> k;
    vector<long> ent(n),ans;
    map<long,long> cant;
    ans.emplace_back(1);
    for(auto &e : ent)
    {
        cin >> e;
    }
    
    for(long pos = 0; pos < k ; pos++)
    {
        long maxn = ent[pos];
        for(int j = 2; j  <= maxn; j++)
        {
           
             if(maxn % j == 0)
            {
                cant[j]++;
                if(cant[j] == k)
                {
                    ans.emplace_back(j);
                }
                while(maxn % j == 0)
                    maxn/=j;
                
            }
        }
    }
    for(long pos = k; pos < n ; pos++)
    {
        long maxn = ent[pos-k];
        for(int j = 2; j  <= maxn; j++)
        {
            
             if(maxn % j == 0)
            {
                cant[j]--;                
                while(maxn % j == 0)
                    maxn/=j;
            }
        }
        maxn = ent[pos];
        for(int j = 2; j  <= maxn; j++)
        {
           
             if(maxn % j == 0)
            {
                cant[j]++;
                if(cant[j] == k)
                {
                    ans.emplace_back(j);
                    
                }
                while(maxn % j == 0)
                    maxn/=j;
            }
        }

    }
    long r=0;
    for(auto &a : ans)
    {
        r = max(r,a); 
    }
    cout << r;
    
    
    
}

int main ()
{
    int tt=1; //cin >> tt;
    while(tt--)
    {
        Solve();
    }
}
/*


*/
/*void Solve()
{
    long n,k;cin >> n >> k;
    vector<long> ent(n);
    for(auto &e : ent)
    {
        cin >> e;
    }
    long ans = 1;
    for(int i = 0; i + k < n; i++)
    {
        long maxn = ent[i];
        for(int j = 0; j < k; j++)
        {
            maxn =__gcd(ent[j+i],maxn);
        }
        for(int j = 2; j * j < maxn; j++)
        {
            if(j == maxn)
                break;
            else if(maxn % j == 0)
            {
                maxn/=j;
                j--;
            }
        }
        ans = max(ans,maxn);
    }
    cout << ans;
}*/