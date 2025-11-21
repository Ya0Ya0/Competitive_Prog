#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
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
    int n;cin >> n;
    vector<vector<int>>g(n);
    for(int i =0; i <n-1;i++)
    {
        int a,b;cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>leaf(n); 
    vector<bool>vis(n);
    auto dfs = [&](auto self,int n)->void
    {
        if(g[n].size() == 1)leaf[n] = 1;
        vis[n] = true;
        for(auto e : g[n])
        {
            if(vis[e])continue;
            self(self,e);
        }
    };
    dfs(dfs,0);
    string color;cin >> color;
    int w = 0,b = 0,nc = 0,wast = 0;
    for(int i =1; i <n;i++)
    {
        if(color[i] == '1' && leaf[i])w++;
        if(color[i] == '0' && leaf[i])b++;
        if(color[i] == '?' && leaf[i])nc++;
        else if(color[i] == '?')wast++;
    }
    ll ans = 0;
    if(color[0] == '?')
    {
        
        ans = max(b,w);
        if(b == w && wast&1)
        {
            ans+=(nc+1)/2;
        }
        else
            ans+=nc/2;
    }
    if(color[0] == '1')
    {
        ans = b;
        ans+=(nc+1)/2;
    }
    if(color[0] == '0')
    {
        ans = w;
        ans+=(nc+1)/2;
    }
    cout << ans <<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}