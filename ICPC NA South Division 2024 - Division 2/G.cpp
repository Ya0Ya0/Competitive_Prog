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
    ll n,m,k; 
    cin >> n >> m >> k;
    // read(ent,n);
    vector<pair<ll,ll>>links(m);
    for(auto &[a,b] : links)cin >> a >> b;
    vector<vector<ll>>adj(n+1);
    for(auto &[a,b] : links)
    {
        adj[a].push_back(b);
    }
    vector<bool>vis(n+1);
    vector<int>par(n+1);
    iota(all(par),0);
    auto g_par = [&](int p,auto self)->int
    {
        if(par[p]==p)
        {
            return p;
        }
        int z = self(par[p],self);
        return z;
    };
    for(int i =0;i < m;i++)
    {
        auto [a,b] = links[i];
        par[b] = g_par(a,g_par);
    }
    map<int,vector<int>>mp;
    for(int i =1;i <=n;i++)
    {
        ll z = g_par(i,g_par);
        mp[z].push_back(i);
    }
    map<int,int>ans;
    for(auto [a,b] : mp)
    {
        bool ok = true;
        for(auto node : b)
        {
            if(adj[node].size()+1!=b.size())
            {
                ok = false;
            }
        }
        if(ok)ans[b.size()]++;
    }
    cout << ans[k] <<"\n";

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