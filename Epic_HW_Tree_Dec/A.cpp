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
int MAX_N = 2*1e5+5;
vector<vector<int>>g(MAX_N);
vector<int>removed(MAX_N);

void Solve()
{
    int n; 
    cin >> n;
    // read(ent,n);
    vector<int>ans(n);
    vector<int>sz(n);
    
    auto comp_sz = [&](auto self,int node, int p)->void{
        sz[node] = 1;
        for(auto neigh : g[node])
        {
            if(!removed[neigh] && p!=neigh)
            {
                self(self,neigh,node);
                sz[node]+=sz[neigh];
            }
            
        }
    };
    auto cent = [&](auto self, int node, int p,int t_sz)->int
    {
        for(auto c : g[node])
        {
            if(c != p && sz[c] > t_sz/2 && !removed[c])
            {
                return self(self,c,node,t_sz);
            }
        }
        return node;
    };
    n-=1;
    while(n--)
    {
        int a,b;cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
    auto get_ans = [&](auto self,int node,int p )->void{
        comp_sz(comp_sz,node,-1);
        int centroid = cent(cent,node,-1,sz[node]);
        ans[centroid] = p;
        removed[centroid] = true;
        for(auto c : g[centroid])
        {
            if(!removed[c])
                self(self,c,centroid);
        }
    };
    get_ans(get_ans,0,-1);
    for(auto p : ans)
    {
        cout << p+1 <<" ";
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