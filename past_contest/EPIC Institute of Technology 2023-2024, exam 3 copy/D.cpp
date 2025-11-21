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
    ll x1, y1, x2, y2;
    ll xb1, yb1, xb2, yb2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> xb1 >> yb1 >> xb2 >> yb2;
    ll ans = 0;
    auto check = [](ll x1, ll y1, ll x2, ll y2, ll xb1, ll yb1, ll xb2, ll yb2)
    {
        ll ans = 0;
        if (x1 < xb1 && xb1 < x2 && y1 < yb1 && yb1 < y2)
        {
            ll t1 = min(abs(xb1 - xb2), abs(xb1 - x2));
            ll t2 = min(abs(yb1 - yb2), abs(yb1 - y2));
            ans -= t1*t2;
        }
        return ans;
    };
    ll z = 0;
    if ((z = check(x1, y1, x2, y2, xb1, yb1,xb2, yb2)) != 0)
        ans = z;
    else if ((z = check(xb2, yb2,xb1, yb1,x1, y1, x2, y2)) != 0)
        ans = z;
    else if ((z = check(x1,y2,x2,y1,xb1,yb2,xb2,yb1)) != 0)
        ans = z;
    else if ((z = check(xb1,yb2,xb2,yb1,x1,y2,x2,y1)) != 0)
        ans = z;
    ans += (x2 - x1) * (y2 - y1) + (xb2 - xb1) * (yb2 - yb1);

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