#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,e;cin >>n >> e;
    vector<vector<int>>g(n);
    for(int i = 0; i < e; i++)
    {
        int a,b; cin >> a >> b;
        a--,b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<bool> vis(n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(vis[i])continue;
        vector<int> q;
        q.push_back(i);
        for(int it = 0; i <=q.size();i++)
        {
            int cur = q[it];
            vis[cur] = true;
            
            for(auto n : g[cur])
            {
                if(!vis[n])
                {
                    q.push_back(n);
                }
            }

        }
        for(auto j : q)
        {
            ans+=q.size()-g[j].size();
        }

    }
    cout << ans;
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