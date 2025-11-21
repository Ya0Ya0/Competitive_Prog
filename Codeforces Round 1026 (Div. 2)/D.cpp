#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
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
    int n,m; 
    cin >> n >> m;
    read(ent,n);
    vector<vector<pair<ll,ll>>>g(n,vector<pair<ll,ll>>());
    for(int i =0;i < m;i++)
    {
        ll a,b,w;cin >> a >> b >> w;
        a--;b--;
        g[a].push_back({b,w});
    }
    ll ok = false;
    vector<ll>dist(n,LONG_LONG_MAX),dist2(n,LONG_LONG_MAX);
    auto dfs = [&](auto self,int v, int p,ll mx,ll mn) -> void
    {
        ll ans = LONG_LONG_MAX;
        dist[v] = min({dist[v],mn});
        for(auto [u,w] : g[v])
        {
            if(u == p || )continue;            
           self(self,u,v,mx+ent[v],max(mn,w));
        }           
        
    };
    dfs(dfs,0,-1,0,0);
    if(dist[n-1]== LONG_LONG_MAX)
    {
        cout << -1 << "\n";
        return;
    }else
    {
        cout << dist[n-1] << "\n";
        return;
    }
    /*auto dfs = [&](auto self,int v, int p,ll mx,ll mn) -> void
    {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,less<pair<ll,ll>>>q;
        q.push({mn,mx});
        ll ans = LONG_LONG_MAX;
        while(!q.empty())
        {
            auto [mn,mx] = q.top();
            q.pop();
            if(mn > dist[v])continue;
            if(mx < dist2[v])continue;
            ans = min(ans,mn);
        }
        dist[v] = min({dist[v],mn});
        dist2[v] = min({dist2[v],mx});
        for(auto [u,w] : g[v])
        {
            if(u == p || mx+ent[v] < w)continue;            
           self(self,u,v,mx+ent[v],max(mn,w));
        }           
        
    };*/
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}