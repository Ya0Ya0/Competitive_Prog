#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long elevar(long long a,long long b){
    long long r=1;
    while(b>0){
        if(b & 1)r=r * a ;
        a=a*a ;
        b/=2;
    }
    return r;
}
void Solve()
{
    ll a,b;
    cin >> a >> b;
    -b/a;
    const ll c = a+b;//2*1000000+20;
    vector<bool>cr(c);
    vector<int>pre(c);
    cr[0] = cr[1] = 0;
    for(ll i = 2; i < c; i++)
    {
        if(cr[i] == 1)continue;
        for(ll j = i; i*j < c; j++)
        {
            cr[i*j] = 1;
        }
    }
    for(ll i = 2; i < c; i++)
    {
        pre[i] = pre[i-1] + (cr[i] == 0);
    }
    ll ans = 0;
    for(int i = 0; i <= a; i++)
    {
        ll z = (double)(i) * (-b)/a + b;
        ans+=pre[z+i] - (i >= 2?pre[i-1] : pre[i]);
        // for(int j = 0; j <= b; j++)
        // {
            
        //     if(j > z)
        //     {
        //         break;
        //     }
        //     if(cr[i+j] == 0)
        //     {
        //         ans++;
        //     }
        // }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}