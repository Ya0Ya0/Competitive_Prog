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
int query(int a, int b)
{
    cout << "? " << a << ' ' << b << "\n";
    cout.flush();   
    int mid;
    cin >> mid;

    return mid;
}
void Solve()
{
    int n;
    cin >> n;

    vector<int>ss(n);
    iota(all(ss),1);
    set<int>vis{all(ss)};
    vector<vector<int>> g(n + 1);
    vis.erase(1);
    int l = 1, r = n;
    while(!vis.empty())
    {        
        l = 1;
        r = *vis.begin();
        int z = query(l, r);
        while (z != l)
        {
            if (vis.count(z) == 0)
            {
                l = z;
            }
            else
            {
                r = z;
            }
            z = query(l, r);
        }
        g[l].push_back(r);
        vis.erase(r);
    }
    cout << "! ";

    for (int i = 1; i <= n; i++)
    {
        for (auto e : g[i])
        {
            cout << i << " " << e << " ";
        }
    }
    cout << "\n";cout.flush();
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;

    while (tt--)
    {
        Solve();
        // cout << "\n";
        // fflush(stdout);
        
    }
}