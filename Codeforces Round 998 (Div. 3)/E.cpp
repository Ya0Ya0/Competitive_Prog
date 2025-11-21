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
    ll n,m1,m2; 
    cin >> n >> m1 >> m2;
    // read(ent,n);
    vector<ll>dsu(n);
    vector<ll>sz(n,1);
    iota(dsu.begin(), dsu.end(), 0);
    function<ll(ll)> find = [&](ll x) {
        if (dsu[x] != x) {
            dsu[x] = find(dsu[x]);
        }
        return dsu[x];
    };
    
    function<void(ll, ll)> union_sets = [&](ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            dsu[b] = a;
            sz[a] += sz[b];
        }
    };
    
    vector<pair<ll,ll>> g1(m1);
    for(int i =0;i <m1;i++)
    {
        ll u,v; cin >> u >> v;
        u--; v--;
        g1[i]={u,v};
    }
    
    ll ans =0;

    vector<ll>dsu2(n),sz2(n,1);
    iota(all(dsu2),0);
    function<ll(ll)> find2 = [&](ll x) {
        if (dsu2[x] != x) {
            dsu2[x] = find2(dsu2[x]);
        }
        return dsu2[x];
    };
    function<void(ll, ll)> union_sets2 = [&](ll a, ll b) {
        a = find2(a);
        b = find2(b);
        if (a != b) {
            if (sz2[a] < sz2[b]) swap(a, b);
            dsu2[b] = a;
            sz2[a] += sz2[b];
        }
    };
    
    for(int i =0;i <m2;i++)
    {
        ll u,v; cin >> u >> v;
        u--; v--;
        union_sets(u, v);
    }
    for(int i =0;i <m1;i++)
    {
        auto [u,v]=g1[i];
        
        if(find(u)!=find(v))
        {
            ans++;
        }else
            union_sets2(u, v);
    }
    ll sets1=0,sets2=0;
    for(int i =0;i <n;i++)
    {
        sets1 += (dsu[i] == i);
        sets2 += (dsu2[i] == i);
    }
    ans+=max(0LL, abs(sets2 - sets1));
    cout << ans << "\n";
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