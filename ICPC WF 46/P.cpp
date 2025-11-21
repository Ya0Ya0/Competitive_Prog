#include <bits/stdc++.h>
using namespace std;
#define ll long long

int num(char c)
{
    if (c == 'R')
        return 0;
    if (c == 'G')
        return 1;
    else
        return 2;
}
ll bfs(vector<vector<int>> &mat, string s)
{
    vector<bool> vis(mat.size());
    ll ans = 0;
    for (ll i = 0; i < mat.size(); i++)
    {
        if (vis[i])
            continue;
        if ()
            stack<int> q;
        q.push(i);
        int carry = 0;
        vector<int> state(mat.size());
        while (!q.empty())
        {
            int j = q.top();
            q.pop();
            carry = num(s[j]);
            for (auto n : mat[i])
                q.push(n);
        }
    }
}
void Solve()
{
    ll n, b;
    cin >> n >> b;
    string s;
    cin >> s;
    vector<vector<ll>> mat(n);
    for (ll i = 0; i < b; i++)
    {
        ll cant;
        cin >> cant;
        while (cant--)
        {
            ll nxt;
            cin >> nxt;
            mat[--nxt].emplace_back(i);
        }
    }
    vector<vector<pair<ll, ll>>> g(n);
    vector<vector<int>> single(n);
    for (ll i = 0; i < n; i++)
    {
        if (mat[i].size() == 2)
        {
            g[mat[i][0]].emplace_back(mat[i][1], (3 - num(s[i]) % 3));
            g[mat[i][1]].emplace_back(mat[i][0], (3 - num(s[i]) % 3));
        }
        if(mat[i].size()==1)
        {
            single[mat[i][0]].emplace_back((3-num(s[i])%3));
        }
        else
        {
            if(num(s[i])!=0)
            {
                cout << " impossible\n";
                return;
            }
        }
        
    }
    vector<bool>vis(n);
    vector<int> col(n,-1);
    for(int i = 0 ; i < n; i++)
    {
        if(vis[i])
            continue;
        int best = INT_MAX;
        for(int ini = 0; ini < 3; ini++)
        {
            vector<int> q(1,i);
            vis[i] = true;
            col[i] = ini;
            for(int j = 0; j < q.size(); j++)
            {
                for(auto [k,sum] : g[q[j]])
                {
                    int val = (3+sum - col[q[j]]) % 3;

                }
            }
        }
    }
}
                queue<int,int> q;

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