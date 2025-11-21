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
    cin >> n >>m>> k;
    // read(ent,n);
    vector<pair<ll,ll>>links(m);
    for(auto &[a,b] : links)cin >> a >> b;
    vector<vector<ll>>adj(n+1);
    for(auto &[a,b] : links)
    {
        adj[a].push_back(b);
    }
    vector<ll>dsu(n+5);// 0 1 2 3 4 5 .. n+4
    __gcd(n,m);
    
    iota(all(dsu),0);
    auto parent = [&](ll a,auto self)->ll
    {
        if(dsu[a] == a)
        {
            return a;
        }
        else{
            return self(dsu[a],self);
        }
        return 0;
    };
    for(auto [a,b] : links)
    {
        ll par = parent(a,parent);
        dsu[b] = par;
    }
    map<ll,ll>countEdges;
    map<ll,ll>countVertices;
    for(ll i =1;i <= n;i++)
    {
        ll par = parent(i,parent); 
        countEdges[par]+=adj[i].size();
        countVertices[par]++;
    }
    map<ll,ll>validSets;
    for(auto [V,cnt] : countVertices)
    {
        ll edges = countEdges[V];//7 /2 == 3
        if(edges == cnt*(cnt-1))// 7 * 6 /2
        {
            validSets[cnt]++;
        }
    }
    cout << validSets[k] << "\n";
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