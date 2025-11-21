#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>>
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
const ll inf = LONG_LONG_MAX;
void Solve()
{
    int n,m,h;cin >> n >> m >> h;
    vector<vector<pair<ll,ll>>>adj(n);
    vector<bool>horse(n);
    for(int i =0;i <h;i++)
    {
        ll ho;cin >> ho;
        horse[ho-1] = true;
    }
    for(int i =0;i <m;i++)
    {
        ll a,b,w;cin >> a >> b >> w;
        a--;b--;
        adj[a].push_back({b,w});

        adj[b].push_back({a,w});
    }
    vector<ll>dw1(n,inf),dw2(n,inf),dh1(n,inf),dh2(n,inf);
    pq wk1,hs1;
    wk1.push({0,0});
    while(!wk1.empty())
    {
        auto [d,cur] = wk1.top();
        wk1.pop();
        if(d > dw1[cur])continue;
        dw1[cur] = d;
        if(horse[cur])
        {
            hs1.push({d,cur});
        }
        for(auto [e,w] : adj[cur])
        {
            if(d + w < dw1[e])
            {
                wk1.push({d+w,e});
            }
            
        }
    }
    while(!hs1.empty())
    {
        auto [d,cur] = hs1.top();
        hs1.pop(); 
        if(d > dw2[cur])continue;
        dw2[cur] = d;       
        for(auto [e,w] : adj[cur])
        {
            if(d + w/2 < dw2[e])
            {
                hs1.push({d+w/2,e});
            }
            
        }
    }
    for(int i =0;i < n;i++)
    {
        dw1[i] = min(dw1[i],dw2[i]);
    }
    //////    
    wk1.push({0,n-1});
    while(!wk1.empty())
    {
        auto [d,cur] = wk1.top();
        wk1.pop();
        if(d > dh1[cur])continue;
        dh1[cur] = d;
        if(horse[cur])
        {
            hs1.push({d,cur});
        }
        for(auto [e,w] : adj[cur])
        {
            if(d + w < dh1[e])
            {
                wk1.push({d+w,e});
            }
            
        }
    }
    while(!hs1.empty())
    {
        auto [d,cur] = hs1.top();
        hs1.pop(); 
        if(d > dh2[cur])continue;
        dh2[cur] = d;       
        for(auto [e,w] : adj[cur])
        {
            if(d + w/2 < dh2[e])
            {
                hs1.push({d+w/2,e});
            }
            
        }
    }
    for(int i =0;i < n;i++)
    {
        dh1[i] = min(dh1[i],dh2[i]);
    }
    ll ans = inf;
    for(int i =0;i <n;i++)
    {
        if(dh1[i] == inf ||dw1[i] == inf )continue;
        ans = min(ans,max(dh1[i],dw1[i]));
    }
    if(ans == inf)
    {
        cout << -1 << "\n";
    }
    else{
        cout << ans << "\n";
    }
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