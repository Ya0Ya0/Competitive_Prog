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
vector<ll> path(ll a, ll b)
{
    vector<ll> l, r;
    while (int(log2(a)) > int(log2(b)))
    {
        l.push_back(a);
        a >>= 1;
        
    }
    while (int(log2(a)) < int(log2(b)))
    {
        r.push_back(b);
        b >>= 1;
        
    }
    while (a != b )
    {
        l.push_back(a);
        r.push_back(b);
        a >>= 1;
        b >>= 1;
        
    }  
    l.push_back(a);
    reverse(r.begin(), r.end());
    for (auto R : r)
        l.push_back(R);
    return l;
}
void Solve()
{
    int n;
    cin >> n;
    vector<ll> ent(n);
    vector<ll> ans(n);
    for (auto &e : ent)
    {
        cin >> e;
    }
    int l = -1, r = -1;
    vector<ll> numbers;
    for (int i = 0; i < n; i++)
    {
        if (ent[i] != -1)
        {
            numbers.push_back(i);
            if (l == -1)
                l = i;
            r = i;
        }
    }
    if (numbers.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << (((i & 1) + 1)) << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = l - 1; i >= 0; i--)
    {
        ent[i] = (l-i) & 1 ? ent[i + 1] * 2 : ent[i + 1] / 2;
    }
    for (int i = r + 1; i < n; i++)
    {
        ent[i] = (r-i) & 1 ? ent[i - 1] * 2 : ent[i - 1] / 2;
    }
    for (int i = 1; i < numbers.size(); i++)
    {
        vector<ll> p = path(ent[numbers[i - 1]], ent[numbers[i]]);
        if (p.size() > numbers[i] - numbers[i - 1]+1 ||
            ((numbers[i] - numbers[i - 1] +1) & 1) != (p.size() & 1))
        {
            cout << -1 << "\n";
            return;
        }
        int j = numbers[i - 1];
        for (auto el : p)
        {
            ent[j++] = el;
        }
        int z = 1;
        while(j < numbers[i])
        {
            ent[j++] = z & 1 ? ent[j - 1] * 2 : ent[j - 1] / 2;
            z^=1;
        }
    }
    for (auto e : ent)
    {
        cout << e << " ";
    }
    cout << "\n";
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