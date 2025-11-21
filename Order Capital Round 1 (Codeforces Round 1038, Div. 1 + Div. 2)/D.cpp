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
    ll n,m; 
    cin >> n>>m;
    vector<vector<int>>adj(n);
    // read(ent,n);
    for(int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<ll>>dist(n),ww(n);
    
    for (int i = 0; i < n; i++)
    {
        dist[i] = vector<ll>(adj[i].size(), LONG_LONG_MAX);
        ww[i] = vector<ll>(adj[i].size(), LONG_LONG_MAX);
    }
    priority_queue<pair<ll, pair<int,ll>>, vector<pair<ll, pair<int,ll>>>, greater<pair<ll, pair<int,ll>>>>q;
    
    for(int i =0;i <adj[0].size();i++)
    {
        dist[0][i] = i;
        ww[0][i] = i;
        q.push({i, {0,i}});
    }
    dist[0][0] = 0;
    while (!q.empty()){
        auto [d, x] = q.top();
        auto [u, w] = x;
        q.pop();
        if (dist[u][d%adj[u].size()] <d || (dist[u][d%adj[u].size()] == d && ww[u][d%adj[u].size()] < w))
            continue;
        cout << "vis" << u<<" " << d%adj[u].size() <<"\n";
        dist[u][d%adj[u].size()] = d;
        ww[u][d%adj[u].size()] = w;
        for (int i = 0; i < adj[u].size(); i++)
        {
            ll v = adj[u][i];
            ll k = i + (i >= d % adj[u].size() ? 0 : adj[u].size());
            ll add = k-(d % adj[u].size()); 
            ll ddd = d+add + 1;
            if ( dist[v][ddd%adj[v].size()] > ddd || (dist[v][ddd%adj[v].size()] == ddd && ww[v][ddd%adj[v].size()] > w + add))
            {
                
                
                dist[v][ddd%adj[v].size()] = ddd;
                ww[v][ddd%adj[v].size()] = w + add;
                q.push({ddd, {v,w+add}});
            }
        }
    }
    ll i = min_element(all(dist[n-1]))-dist[n-1].begin();
    cout << dist[n-1][i] << " " << ww[n-1][i] << "\n";
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