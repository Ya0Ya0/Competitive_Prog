#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = r * a;
        a = a * a;
        b /= 2;
    }
    return r;
}
void Solve()
{
    ll n,x;cin >> n >> x;
    vector<ll>val(n);
    for(auto &a : val)cin >> a;
    vector<vector<ll>>g(n);
1
1
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(abs(val[i]-val[j])%x == 0)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    auto dfs = [&](int v)
    {
        vector<bool>vis(n);
        vector<pair<int,int>>ans;
        stack<pair<int,int>> s;
        s.push({v,-1});
        while(!s.empty())
        {
            auto [node,par] = s.top();
            s.pop();
            if(vis[node])continue;
            vis[node] = true;
            ans.push_back({node,par});
            for(auto e : g[node])
            {
                s.push({e,node});
            }
        }
        return ans;
    };
    auto ans = dfs(0);
    if(ans.size()!=n-1)
    {
        cout << "NO\n";return;
    }
    cout << "YES\n";
    for(auto [a,b] : ans)
    {
        cout << a+1 << " " << b+1 <<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}