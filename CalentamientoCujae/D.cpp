#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,m,z=1;
    vector<pair<int,int>>mov = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)};
    while(cin >> n)
    {
        cin >> m;
        vector<vector<char>>g(n,vector<char>(m));
        for(int j = 0; j < n; j++)
        {
            string s; cin >> s;
            for(int i = 0; i < m; i++)
                g[j][i] = s[i];

        }
        int ans = 0;
        vector<vector<bool>>vis(n,vector<bool>(m));
        queue<pair<int,int>> q;
         for(int j = 0; j < n; j++)
            for(int i = 0; i < m; i++)
                {
                    if(g[j][i] == '#')continue;
                    if(vis[j][i])continue;                    
                    q.push({j,i});
                    while(!q.empty())
                    {                     
                        auto [a,b] = q.front();q.pop();
                        if(g[a][b] == '#'){vis[a][b] = true;continue;}
                        if(vis[a][b])continue;
                        vis[a][b]=true;
                        for(auto [c,d] : mov)
                        {
                            int aa=a+c,bb=b+d;
                            if(aa<0 || bb < 0 || aa == n || bb == m)
                                continue;
                            if(vis[aa][bb] || g[aa][bb]=='#')continue;
                            q.push({aa,bb});
                        }
                    }
                    ans++;

                }
        cout <<"Case "<<z++<<": "<<ans<<"\n";
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
 //   cin >> tt;
    while (tt--)
    {
        Solve();
    }
}