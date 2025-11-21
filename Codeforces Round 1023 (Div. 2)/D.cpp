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


const int MAXN = 2e5;
const int MAXLOG = 18;
 
int n;
vector<int> g[MAXN];
int sz[MAXN];
int tin[MAXN];
int par[MAXN];
int rem[MAXN];

 

 
int timer = 0;
pair<int,int> dfs2(int vertex, int parent = -1,int depth=1) {
    sz[vertex] = 1;
    int posnow = -1, posmax = 0;
    par[vertex] = parent;
    ll d = depth,v = vertex;
    for (int posnow = 0; posnow < g[vertex].size(); posnow++) {
        int son = g[vertex][posnow];
        if (son != parent && !rem[son]) {
	        auto k = dfs2(son, vertex,depth+1);
            
            if(k.first > d)
            {
                d = k.first;v = k.second;
            }else if(k.first == d && k.second > v)
            {
                d = k.first;v = k.second;
            }
	        // if (sz[son] > sz[g[vertex][posmax]]) {
	        //     posmax = posnow;
	        // }
	        sz[vertex] += sz[son];
        }
    }
    // rem[v] = true;
    return {d,v};
    // if(g[vertex].size())
    // swap(g[vertex][0], g[vertex][posmax]);
}
pair<int,int> dfs(int vertex, int parent = -1,int depth=1) {
    sz[vertex] = 1;
    int posnow = -1, posmax = 0;
    ll d = depth,v = vertex;
    for (int posnow = 0; posnow < g[vertex].size(); posnow++) {
        int son = g[vertex][posnow];
        if (son != parent && !rem[son]) {
	        auto k = dfs(son, vertex,depth+1);
            if(k.first > d)
            {
                d = k.first;v = k.second;
            }else if(k.first == d && k.second > v)
            {
                d = k.first;v = k.second;
            }
	        // if (sz[son] > sz[g[vertex][posmax]]) {
	        //     posmax = posnow;
	        // }
	        sz[vertex] += sz[son];
        }
    }
    return {d,v};
    // if(g[vertex].size())
    // swap(g[vertex][0], g[vertex][posmax]);
}
 
// void calc(int v, int p = 0, int root = -1) {
//     tin[v] = timer++;
//     pre[v][0] = p;
//     for (int i = 1; i < MAXLOG; i++) {
//         pre[v][i] = pre[pre[v][i - 1]][i - 1];
//     }
//     if (root == -1) {
//         root = v;
//     }
//     rt[v] = root;
//     int alr = 0;
//     for (auto to : g[v]) {
//         if (to == p) {
//             continue;
//         }
//         if (!alr) {
//             calc(to, v, root);
//             alr = 1;
//         }
//         else {
//             calc(to, v);
//         }
//     }
// }
 
int isp(int a, int b) {
    return tin[a] <= tin[b] && tin[b] <= tin[a] + sz[a] - 1;
}
 
// int lca(int a, int b) {
//     if (isp(a, b)) {
//         return a;
//     }
//     if (isp(b, a)) {
//         return b;
//     }
//     for (int i = MAXLOG - 1; i >= 0; i--) {
//         if (!isp(pre[a][i], b)) {
//             a = pre[a][i];
//         }
//     }
//     return pre[a][0];
// }
 
inline void init() {
 
}
 
inline void solve() {
    init();
    cin >> n;
    vector<ll>tw(n);
    // for(auto &t : tw)cin >> t;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> ans;
    vector<int>nod(n);
    for(int i =0;i <n;i++)
    {
        if(!rem[i])
        {
            vector<int>cur;
            auto far = dfs(i,-1,1);
            auto f2 = dfs2(far.second,-1,1);
            int z = f2.second;
            while(z!=far.second)
            {
                rem[z] = true;
                z = par[z];
            }
            
            rem[z]=true;
            cur.push_back (f2.first); 
            cur.push_back (max(far.second,f2.second)+1); 
            cur.push_back (min(far.second,f2.second)+1); 
            ans.push_back(cur);
        }
        if(!rem[i])i--;
    }
    sort(all(ans));
    reverse(all(ans));
    for(auto cc : ans)
    {
        for(auto c : cc)
            cout << c <<" ";
    }
    for(int i =0;i <n;i++){g[i].clear();rem[i] = false;}
    cout <<"\n";
    
   
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt =0;cin >> tt;
    while ( tt--) {
    solve();
	 }
    return 0;
}