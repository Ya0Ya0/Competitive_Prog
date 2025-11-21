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
    int n,q; 
    cin >> n >> q;
    // read(ent,n);
    vector<vector<int>>adj(n);
    for(int i =0;i < n-3;i++)
    {
        int a,b;cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>down(n);
    vector<int>par(n);
    vector<pair<int,int>>up(n);
    iota(all(par),0);
    auto dfs1 = [&](int node, int parent,int og,auto self)->void
    {
        int mx_dw = 0;
        par[node] = og;
        for(auto a : adj[node])
        {
            if(a != parent)
            {
                self(a,node,og,self);
                mx_dw = max(mx_dw,down[a]);
            }
        }
        down[node] = mx_dw+1;
    };
    vector<int>island;
    for(int i =0;i < n;i++)
    {
        if(par[i]==i)
        {
            dfs1(i,-1,i,dfs1);
            island.push_back(i);
        }
    }
    auto dfs2 = [&](int node, int parent,auto self)->int
    {
        int mx_dw1 = 0; 
        int mx_dw2 = 0;        
        for(auto a : adj[node])
        {
            if(a != parent)
            {                
                mx_dw1 = max(mx_dw1,down[a]);
                if(mx_dw1 > mx_dw2)swap(mx_dw1,mx_dw2);
            }
        }
        if(parent!=-1)
        {
            auto [a,b] = up[parent];
            int upp = a;
            if(a-2 == mx_dw2)
            {
                upp = b;
            }
            mx_dw1 = max(mx_dw1,upp);
            if(mx_dw1 > mx_dw2)swap(mx_dw1,mx_dw2);
        }
        up[node] = {mx_dw2+1,mx_dw1+1};
        int diam = up[node].first;
        for(auto a : adj[node])
        {
            if(a != parent)
            {                
                diam = max(diam,self(a,node,self));
            }
        }
        return diam;
    };
    map<int,int>diam;
    for(int i =0;i < n;i++)
    {
        if(par[i]==i)
        {
            diam[i] = dfs2(i,-1,dfs2);
        }
    }
    for(int i =0;i <q;i++)
    {
        int a,b;cin >> a >> b;
        a--;b--;
        set<int>mid{all(island)};
        mid.erase(par[a]);
        mid.erase(par[b]);
        int ans = diam[*mid.begin()];
        ans+=up[a].first;
        ans+=up[b].first;
        cout << ans <<"\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}