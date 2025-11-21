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
    ll n, y, a;
    cin >> n >> y >> a;

    auto fac = [&](ll x) -> map<ll, ll>
    {
        map<ll, ll> ans;
        ll p = 2;
        while (x > 1)
        {

            while (x % p != 0)
                p++;
            // if (p * p > x)
            //     p = x;
            while (x > 1 && x % p == 0)
            {
                x /= p;
                ans[p]++;
            }
            p++;
        }
        return ans;
    };
    auto fa = fac(y);
    auto fb = fac(n);
    map<ll, ll> mul, div;
    for (auto [a, b] : fa)
    {
        ll aa = 0;
        if (fb.count(a))
        {
            aa = fb[a];
        }
        if (b > aa)
        {
            mul[a] = b - aa;
        }
    }
    for (auto [a, b] : fb)
    {
        ll aa = 0;
        if (fa.count(a))
        {
            aa = fa[a];
        }

        if (b > aa)
        {
            div[a] = b - aa;
        }
        
    }
    deque<ll> mm, dd;
    for (auto [a, b] : mul)
    {
        for (int i = 0; i < b; i++)
        {
            mm.push_back(a);
        }
    }
    for (auto [a, b] : div)
    {
        for (int i = 0; i < b; i++)
        {
            dd.push_back(a);
        }
    }
    ll ope = 0;
    while (!mm.empty())
    {
        if (mm.back() > a)
        {
            cout << -1 << "\n";
            return;
        }
        ll cur = mm.back();
        mm.pop_back();
        while (!mm.empty() && cur * mm.back() <= a)
        {
            cur *= mm.back();
            mm.pop_back();
        }
        while (!mm.empty() && cur * mm.front() <= a)
        {
            cur *= mm.front();
            mm.pop_front();
        }
        ope++;
    }
    while (!dd.empty())
    {
        if (dd.back() > a)
        {
            cout << -1 << "\n";
            return;
        }
        ll cur = dd.back();
        dd.pop_back();
        while (!dd.empty() && cur * dd.back() <= a)
        {
            cur *= dd.back();
            dd.pop_back();
        }
        while (!dd.empty() && cur * dd.front() <= a)
        {
            cur *= dd.front();
            dd.pop_front();
        }
        ope++;
    }
    cout << ope << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}