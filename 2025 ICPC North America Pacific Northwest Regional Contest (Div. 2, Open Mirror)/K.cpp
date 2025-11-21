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
    int n,m,k;cin >> n >> m >> k;
    vector<ll>pr(n);for(auto &e : pr)cin >> e,e--;
    vector<vector<int>>adj(n);
    for(int i =0;i < m;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pair<int,int>>s;
    vector<bool>vis(n);
    vector<ll>dis(k,0);
    vector<ll>diss(n,-1);
    dis[pr[0]] = -1;
    s.push({0,0});
    while(!s.empty()){
        auto [cur,par] = s.front();
        s.pop();
        if(vis[cur])continue;
        vis[cur] = true;
        diss[cur] = diss[par]+1;
        dis[pr[cur]] = max(dis[pr[cur]],diss[cur]);
        for(auto e : adj[cur])
        {
            if(vis[e])continue;           
            s.push({e,cur});
        }
    }
    for(auto e : dis)cout << e <<" ";
    cout <<"\n";
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