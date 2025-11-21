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
    ll n, k;
    cin >> n >> k;
    ll maxPos = 0;
    for (ll i = 1; i <= n; i++)
    {
        maxPos += abs(i - (n - i + 1));
    }
    if (k > maxPos || k & 1)
    {
        cout << "No\n";
    }
    vector<ll> ans(n);
    for (int i = 1; k; i++)
    {
        if(k > abs(i - (n - i + 1)))
        {
            k -= abs(i - (n - i + 1));
            ans[i-1] = (n - i + 1);
            ans[n - i] = i;
        }
        else
        {
            ans[i-1] = i;
        }
    }
    cout << "YES\n";
    for(auto a : ans)
    {
        cout << a << " ";
    }
    cout <<"\n";
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