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
ll c = 5001;
void Solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c)
    {
        cout << -1 << "\n";
        return;
    }

    int h = 0;
    long long z = 1;
    int lst_layer = 0;
    if (!a)
    {
        cout << b << "\n";
        return;
    }
    while (a >= z)
    {
        h++;
        a -= z;
        z <<= 1;
    }
    lst_layer = elevar(2, h);

    // making everything same hight with one clidrens(b)
    if (a)        
    {
        h++;
        int ax = min(b, lst_layer - a);
        b -= ax;
        lst_layer += a;
    }
    h += (b + lst_layer - 1) / lst_layer;

    cout << h << "\n";
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