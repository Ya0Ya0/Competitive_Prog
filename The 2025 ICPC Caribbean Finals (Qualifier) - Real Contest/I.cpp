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
ll mod = 998244353;
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a)%mod;
        a = (a * a)%mod;
        b /= 2;
    }
    return r%mod;
}
void Solve()
{
    ll n,k; 
    cin >> n >> k;
    read(ent,n);
    sort(all(ent));
    vector<ll>adds(n);

    for(ll i=0;i<n-1;i++)
    {
        ll dif = ent[i+1]-ent[i];
        if(dif <= 0)continue;
        if(dif > 0 && k > dif*(i+1))
        {
            k -= dif*(i+1);            
            adds[i] += dif;            
        }
        else
        {
            ll val = k/(i+1);            
            adds[i] += val;            
            k -= val*(i+1);
            if(k)
            adds[k-1]++;
            
            k = 0;
            break;
        }        
    }
    if(k > 0)
    {
        ll val = k/n;
        adds[n-1] += val;
        k -= val*n;
        if(k)
        adds[k-1]++;
        k = 0;
    }
    for(int i =n-1;i>0;i--)
    {
        adds[i-1] += adds[i];
    }
    
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        sum = (sum + (elevar(ent[i]+adds[i],mod-2))%mod)%mod;
    }
    sum = (sum * elevar(n,mod-2))%mod;
    cout << sum << "\n";
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