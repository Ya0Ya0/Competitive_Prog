#include "bits/stdc++.h"
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
const ll mod = 998244353;
const ll MAX = (1e5 + 7) * 2;
ll factorial[MAX];
void Solve()
{
    int n;
    cin >> n;
    vector<ll> ent(2 * n);
    ll less = n, big = n;
    ll extra = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> ent[i];
        if (ent[i] != 0)
        {
            if (ent[i] > n)
                big--;
            else
                less--;
        }
    }
    ll ans = 1;
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (ent[i] == 0 && ent[i + 1] == 0)
            extra++;
        else if (ent[i + 1] == 0)
        {
            if (ent[i] <= n)
            {
                ans = (ans *big)%mod;
                big--;
            }
            else{
                ans = (ans*less)%mod;
                less--;
            }
        }
        else if(ent[i] == 0)
        {
            if (ent[i+1] <= n)
            {
                ans = (ans *big)%mod;
                big--;
            }
            else{
                ans = (ans*less)%mod;
            }
        }
    }
    for(int i =2;i <=extra*2;i+=2)
    {
        ans = (ans*i)%mod;
    }
    if(extra)
        ans= ((ans*factorial[extra])%mod) ;
    cout << ans <<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    factorial[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        factorial[i] = (factorial[i - 1] * i)%mod;
    }
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}