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
    map<ll, ll> mp;
    map<ll, ll> mp2;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll>ent(n);
    for(auto&e : ent)cin >> e;
    for(int i =0; i < m; i++)
    {
        ll k; cin >> k;
        mp[k] = 1;
    }
    int duos = 0;
    for(int i =0; i < m; i++)
    {        
        mp2[ent[i]]++;
        if(mp.count(ent[i]) && mp[ent[i]] >=mp2[ent[i]])
            duos++;
    }
    ll ans = duos>=k?1 : 0;    
    for(int i = m; i < n; i++)
    {        
        mp2[ent[i-m]]--;
        if(mp.count(ent[i-m]) && mp2[ent[i-m]] < mp[ent[i-m]])
            duos--;
        mp2[ent[i]]++;
        if(mp.count(ent[i]) && mp[ent[i]] >=mp2[ent[i]])
            duos++;
        if(duos>=k)
        {
            ans++;
        }
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