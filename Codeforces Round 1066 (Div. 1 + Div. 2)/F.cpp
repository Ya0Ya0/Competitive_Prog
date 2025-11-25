#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
        cin >> e;
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
    int n;
    cin >> n;
    // read(ent,n);
    vector<bool> vis(n + 5);
    ll coins = 0;
    vector<pair<ll, ll>> mis;
    ll cur = 3;
    for (ll i = 0; i < 18; i++)
    {
        if ((cur) > n)
            break;
        mis.push_back({n + 1, 1});
        coins += 1000;
        bool k = false;
        for (ll j = n - 1; j > 0; j--)
        {
            if ((j % cur == cur / 3) )
            {
                k = 1;
                mis.push_back({j, min(cur/3, n - j)});
                coins += min(cur/3, n - j);
                
            }
        }
        mis.push_back({n + 1, 1});
        coins += 1000;
        for (ll j = n - 1; j > 0; j--)
        {
            if ((j % cur == cur*2 / 3) )
            {
                k = 1;
                mis.push_back({j, min(cur/3, n - j)});
                coins += min(cur/3, n - j);
                
            }
        }       
        cur *= 3;
    }
    coins -= 1000;
    cout << coins << "\n";
    cout << mis.size() << "\n";
    
    // for(auto [a,b] : mis)
    // {
    //     cout << a << " " << b << "\n";
    // }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}