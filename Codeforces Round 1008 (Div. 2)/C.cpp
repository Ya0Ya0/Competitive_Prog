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
void random_sort(vector<pair<ll, ll>> &arr)
{
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
}
void Solve()
{
    int n;
    cin >> n;
    n *= 2;
    read(ent, n);

    vector<pair<ll, ll>> v(n);
    ll k = 0;
    map<ll, ll> mp;
    for (auto e : ent)
    {
        mp[e]++;
        v[k].first = e;
        v[k++].second = k;
    }
    bool ok = false;
    while (!ok)
    {
        random_sort(v);
        ll t = 0;
        ll l = 0;
        for (int i = 0; i < n; i++)
        {
            t += v[i].first;
        }
        for (int i = 0; i < n / 2; i++)
        {
            l += v[i].first;
        }
        ll r = t - l;
        if (l < r)
        {
            swap(l, r);
            for (int i = 0; i < n / 2; i++)
            {
               swap(v[i],v[i+n/2]);
            }
            
        }
        if (mp[l-r] == 0)
        {
            cout << l-r << " ";
            for (int i = 0; i < n / 2; i++)
            {
                cout << v[i].first << " " << v[i + n / 2].first << " ";
            }
            break;
        }
        ll k = -(l - v[0].first) + r + v[0].first;
        if (k > 0 && mp[k] == 0)
        {
            cout << v[0].first << " ";
            v[0].first = k;
            for (int i = 0; i < n / 2; i++)
            {
                cout << v[i].first << " " << v[i + n / 2].first << " ";
            }

            break;
        }
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