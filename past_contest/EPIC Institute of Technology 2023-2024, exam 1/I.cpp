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
    ll n;
    cin >> n;
    vector<ll> val(3 * n);
    for(int i = 0; i < 3*n; i++)cin >> val[i];
    priority_queue<ll, vector<ll>, greater<ll>> t;
    priority_queue<ll, vector<ll>, greater<ll>> l;
    priority_queue<ll, vector<ll>> r;
    vector<ll>resl(n*3),resr(n*3);
    ll cur = 0;
    for (ll i = 0; i < 3 * n; i++)
    {        
        cur+=val[i];
        l.push(val[i]);   
        resl[i] = cur;     
        if(i < n)continue;
        auto mini = l.top();
        l.pop();
        cur-=mini;
        resl[i] = cur;     
        
    }
    cur = 0;
    for(ll i = 3*n-1; i >=0; i--)
    {
        cur+=val[i];
        r.push(val[i]); 
        resr[i] = cur;       
        if(i >=2*n)continue;
        auto maxi = r.top();
        r.pop();
        cur-=maxi;
        resr[i] = cur;    
        
    }
    ll ans = LONG_LONG_MIN;
    for(int i = n-1; i < 2*n; i++)
    {
        ans = max(ans,resl[i]-resr[i+1]);
    }
    cout << ans ;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}