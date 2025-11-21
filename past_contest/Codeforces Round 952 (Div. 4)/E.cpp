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
void Solve()
{
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans = 0;
    set<pair<int, int>> s;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if ((i * j) > k)
                break;
            if (k / (i * j) > c)
                continue;
            if (k % (i * j) != 0)
                continue;
            ll v = k / (i * j);

            // if (s.count({i, j}) || s.count({j, v}) || s.count({v,j}) || s.count({j,i}) || s.count({i,v}) || s.count({v,i}))
            //     continue;
            // s.insert({i, j});
            ans = max(ans,(a - i + 1) * (b - j + 1) * (c - v + 1));
        }
    }
    cout << ans << '\n';
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