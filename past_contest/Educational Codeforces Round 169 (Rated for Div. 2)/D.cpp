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
ll t = 0;
void Solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> b(n + 1), r(n + 1), g(n + 1), y(n + 1);
    vector<string> c(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        c[i] = s;
        if (s[0] == 'B' || s[1] == 'B')
            b[i + 1] = b[i] + 1;
        else
            b[i + 1] = b[i];
        if (s[0] == 'G' || s[1] == 'G')
            g[i + 1] = g[i] + 1;
        else
            g[i + 1] = g[i];
        if (s[0] == 'R' || s[1] == 'R')
            r[i + 1] = r[i] + 1;
        else
            r[i + 1] = r[i];
        if (s[0] == 'Y' || s[1] == 'Y')
            y[i + 1] = y[i] + 1;
        else
            y[i + 1] = y[i];
    }
    auto ck = [&](ll a, ll b)
    {
        if (c[a][0] == c[b][0] || c[a][0] == c[b][1] || c[a][1] == c[b][0] || c[a][1] == c[b][1])
            return true;
        return false;
    };
    auto f = [&](char c)
    {
        if (c == 'B')
            return b;
        if (c == 'Y')
            return y;
        if (c == 'G')
            return g;
        if (c == 'R')
            return r;
    };
    while (q--)
    {
        t++;

        ll a, b;
         cin >> a >> b;
        // if (t == 426)
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         cout << c[i] ;
        //     }
        //     cout <<a << b <<"\n";continue;
        // }
        if (a > b)
            swap(a, b);
        ll ans = LONG_LONG_MAX;
        if (ck(a - 1, b - 1))
        {
            cout << abs(b - a) << "\n";
            continue;
        }
        for (auto cd : c[b - 1])
        {

            ll cur = 0;
            auto o = f(cd);
            ll p = (o[a] + 1);
            auto k = lower_bound(all(o), p);
            if (k - o.begin() == b)
                k = lower_bound(all(o), (p + 1));
            if (k != o.end())
            {
                cur += abs(k - o.begin() - a);
                cur += abs(k - o.begin() - b);
                ans = min(cur, ans);
            }
        }

        for (auto cd : c[b - 1])
        {
            auto o = f(cd);
            ll cur = 0;
            if (o[a] < 1)
                continue;
            auto k = lower_bound(all(o), o[a]);
            if (k - o.begin() != b)
            {
                cur += abs(k - o.begin() - a);
                cur += abs(k - o.begin() - b);
                ans = min(cur, ans);
            }
        }
        if (ans == LONG_LONG_MAX)
            ans = -1;
        cout << ans << "\n";
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
/*
BG RY BG 
23
*/