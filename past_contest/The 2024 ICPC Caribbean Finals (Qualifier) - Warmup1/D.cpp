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
const ll MAX = 1e9;
void Solve()
{
    int n;
    cin >> n;
    vector<ll> ent(n);
    auto divi = [](ll n)
    {
        int ans = 0, i = 2;
        while (n>1)
        {
            while (n>1 && n % i == 0)
            {
                n /= i;
                if (i & 1)
                    ans++;
                
            }
            i++;
        }
        return ans;
    };
    for (auto &e : ent)
        cin >>
            e;
    //vector<short int> cr(MAX, 1);
    ll ans = 0;
    for (auto &e : ent)
    {
        ans ^= divi(e)+1;
    }
    if (ans)
    {
        cout << "Alice";
    }
    else
    {
        cout << "Bob";
    }
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