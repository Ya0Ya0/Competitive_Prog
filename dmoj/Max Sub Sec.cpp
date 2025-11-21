#include <bits/stdc++.h>
using namespace std;


void Solve()
{
    int n;cin >> n ;
    vector<int> ent(n);
    
    for(auto &e : ent)
    {
        cin >> e;
    }
    vector<int> vis(n);
    for(int i = n - 1; i >= 0; i--)
    {
        int count = 1;
        if(vis[i] == 0)
        {
            int last = ent[i];
            for(int j = i-1; j >= 0; j--)
            {
                if(ent[j] + 1 == last )
                {
                    last = ent[i];
                    vis[j] = (max(vis[j],++count));
                }
            }
        }
    }
    int ans = 2;
    for(int i = 0; i < n; i++)
    {
        ans = 0;
        for(int j = i + 1; j < n; j++ )
        {
            if(ent[j]-ent[i] == 2)
            {
                
            }
        }
    }
}

int main ()
{
    int tt=1; //cin >> tt;
    while(tt--)
    {
        Solve();
    }
}