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
    ll mx = 0;
    ll ans = LONG_LONG_MAX;
    auto sum_dig = [](ll n)
    {
        ll ans = 0;
        for (ll i = 0; i < log10(n + 9); i++)
        {
            ll t = (n / pow(10, i));
            ans += t % 10;
        }
        return ans;
    };
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (mx < sum_dig(i))
            {
                mx = sum_dig(i);
                ans = i;
            }
            else if (mx == sum_dig(i))
            {               
                ans = min(ans,i);
            }
            if (mx < sum_dig(n/i))
            {
                mx = sum_dig(n/i);
                ans = n/i;
            }
            else if (mx == sum_dig(n/i))
            {               
                ans = min(ans,n/i);
            }
        }
    }
    cout << ans;
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