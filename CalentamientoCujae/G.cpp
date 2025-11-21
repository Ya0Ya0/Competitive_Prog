#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,m;cin >>n >> m;
    vector<vector<int>> g(27);
    for(int i = 0; i < n; i++)
    {
        char a,b;
        cin >> a >> b;
        g[a-'a'].push_back(b-'a');
        
    }
    while(m--)
    {
        string s1,s2;cin >>s1 >> s2;
        if(s1.size()!=s2.size())
        {
            cout << "no\n";continue;
        }
        else
        {
            bool okok=true;
            for(int i = 0 ;i < s1.size();i++)
            {
                queue<int> q;
                vector<bool>vis(27);
                q.push(s1[i]-'a');
                bool ok = false;
                while(!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    vis[cur] = true;
                    if(cur == s2[i]-'a')
                    {
                            
                        ok = true;
                        break;
                    }
                    for(auto e : g[cur])
                    {
                        if(!vis[e])
                        {
                            q.push(e);
                        }
                        
                    }
                    if(ok) break;
                }
                if(!ok) {okok=false;break;}
            }
            if(okok)
            {
                cout << "yes\n";
            }
            else cout << "no\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}