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
    ll n;cin >> n;
    vector<ll>val(n);
    for(auto &v : val)
    {
        cin >> v;
    }
    ll cur = 0;
    ll ans = 0;
    for(int i = 1; i  <n; i++)
    {
        if(val[i] < val[i-1])
        {
            if(val[i] == 1)
            {
                cout << -1 << '\n';return;
            }   
            ll l = val[i-1],r = val[i];
            ll ope = 0;
            while(l > r)
            {
                ope++;
                r*=r;
            }
            cur += ope;
            ans += cur;  
        }
        else if(cur >= 1)
        {           
            ll l = val[i-1],r = val[i];
            ll ope = 0;
            while(l < r)
            {
                ope++;
                l*=l;                
            }
            if(l == r)ope++;
            ll curope = cur - ope+1;
            if(curope < 0)
            {
                cur = 0;continue;
            }
            cur = curope;
            ans+=cur;            
        }
    }
    cout << ans << "\n";
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