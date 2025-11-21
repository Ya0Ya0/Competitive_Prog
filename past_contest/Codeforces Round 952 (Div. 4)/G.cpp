#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
ll mod = 1000000000 + 7;
long long elevar(long long a,long long b){
    long long r=1;
    while(b>0){
        if(b & 1)r=r * a % mod;
        a=a*a %mod;
        b/=2;
    }
    return r;
}
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
void Solve()
{
    ll l, r, k;
    cin >> l >> r >> k;
    ll ans = 0;
    ll num = 10 / k;
    if(10%k)
        num = 10 / k;
    else 
        num = 10 / k-1;
    
    if (num > 10)
    {
        cout << 0 << "\n";
        return;
    }
    if(num == 10 )
    {
        cout << elevar(10,r)-elevar(10,l) <<"\n";
        return;
    }
    vector<vector<ll>> m = {{num + 1, 0}, {num + 1, 1}};
    auto mul = [&](vector<vector<ll>> a, vector<vector<ll>> b)
    {
        vector<vector<ll>> t{{0, 0}, {0, 0}};
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                for (ll k = 0; k < 2; k++)
                {
                    t[i][k] = (t[i][k] + (a[i][j] * b[j][k]) % mod) % mod;
                }
            }
        }
        return t;
    };

    vector<vector<ll>> rm = {{num, 0}, {num, 0}};
    l--;
    if (l == -1)
        rm[1][0] = 0;
    while (l > 0)
    {
        if (l & 1)
        {
            rm = mul(m, rm);
        }
        m = mul(m, m);
        l /= 2;
    }
    ll ans1 = rm[1][0];

    rm = {{num, 0}, {num, 0}};
    m = {{num + 1, 0}, {num + 1, 1}};
    r--;
    while (r > 0)
    {
        if (r & 1)
        {
            rm = mul(m, rm);
        }
        m = mul(m, m);
        r /= 2;
    }
    ll ans2 = rm[1][0];
    ans = (ans2 - ans1+mod)%mod;
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