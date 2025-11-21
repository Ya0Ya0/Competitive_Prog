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
long long elevar(long long a, long long b, ll c)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a) % c;
        a = a * a;
        b /= 2;
    }
    return r;
}
void Solve()
{
    ll n, d;
    cin >> n >> d;
    if (n >= 10)
    {
        cout << "1 3 5 7 9\n";
        return;
    }
    ll tr = 100;
    ll f = 100;
    ll se = 100;
    ll ni = 100;
    ll ini = 10;
    ll fac = 1;
    vector<ll> seven{3};

    fac = 1;
    for (int i = 1; i <= min(8LL,n); i++)
    {
        fac = fac * i;
    }
    cout << "1 ";
    if (n >= 3 || (d * fac % 3 == 0))
    {
        cout << "3 ";
    }
    if (d == 5)
    {
        cout << "5 ";
    }
    if (n >= 3)
    {
        //|| (d*n%5==0)
        cout << "7 ";
    }
    else
    {

        ll cur = 0;
        for (int i = 1; i <= fac; i++)
        {
            cur = (cur + elevar(10, i - 1, 7)) % 7;
        }
        if (cur * d % 7 == 0)
        {
            cout << "7 ";
        }
    }
    if (n >= 6 || (d * fac % 9 == 0))
    {
        cout << "9 ";
    }
    cout << "\n";
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