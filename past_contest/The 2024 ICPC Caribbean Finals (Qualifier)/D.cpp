#include "bits/stdc++.h"
using namespace std;
#define ll long long
// #define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
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
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<int> tp(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll b, ty;
        cin >> ty >> b;
        tp[i] = ty;
        for (int j = 0; j < b; j++)
        {
            int a;
            cin >> a;
            
                adj[i].push_back(a);
        }
    }
    vector<bool> vis(n + 1);
    // cnt de emisores hasta i
    vector<int> cnt(n + 1);
    // cnt de emisores buenos hasta i
    vector<int> cnt2(n + 1);
    // 1 si hay un camino hasta un emisor
    vector<int> ok(n + 1);
    // componentes
    vector<int> comp(n + 1);
    iota(all(comp),0);

    int ans = 0, str = 0;
    auto dfs = [&](auto self, int c, int p)->bool
    {
        
    };
    for(int i =1;i <=n;i++){
        
        if(!vis[i])
            dfs(dfs,i,0);
    }
    cout << ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}