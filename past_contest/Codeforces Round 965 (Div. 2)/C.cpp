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
    ll n,k;cin >> n >> k;
    vector<ll>ent(n),bin(n),ord(n);
    iota(all(ord),0);
    for(int i = 0; i < n; i++)
    {
        cin >> ent[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> bin[i];
    }
    sort(all(ord),[&](int a, int b)
    {
        return ent[a] > ent[b];
    });
    ll imp1 = n/2,imp2 = n/2+1;
    while(k)
    {
        ll inc  = 0;
        ll elem = 1;
        ll cur = imp1;
        if(bin[ord[cur]] == 1)
        {           
            
            ll plus = max(k,(ent[ord[cur+1]]-ent[ord[cur]])*elem);
            inc+=plus
            cur++;
        }

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