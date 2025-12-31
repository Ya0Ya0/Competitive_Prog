#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
        cin >> e;
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
ll const mod = 998244353;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a + mod) % mod;
        a = (a * a + mod) % mod;
        b /= 2;
    }
    return r;
}
// ll const mod = 998244353;
void Solve()
{
    int n;
    cin >> n;
    vector<vector<pair<ll,ll>>> g(n);
    // read(ent, n);
    for(int i =0;i < n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    vector<ll> rem(n);
    ll ok = true;
    vector<ll>ans;
    auto dfs = [&](auto self,int u, int p,int edge) -> ll
    {
        ll cur =1;
        for (auto &[v, i] : g[u])
        {
            if (v == p)
                continue;            
            cur+=self(self,v, u, i);
        }
        if(cur == 3)
        {
            ans.push_back(edge+1);
            return 0;
        }
        if(cur > 3)
            ok = false;
        return cur;
    };
    ll cur = dfs(dfs,0,-1,-2);
    if(!ok || cur != 0)
    {
        cout << -1 << endl;
        return;
    }
   
    cout << ans.size()-1 << endl;
    for(int i = 0; i < ans.size()-1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}