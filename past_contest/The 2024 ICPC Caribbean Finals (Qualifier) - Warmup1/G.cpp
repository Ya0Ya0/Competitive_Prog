#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
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
const ll MAX = 1e9;
void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ent(n);
    for (auto &e : ent)
        cin >> e.first >> e.second;
    
    
    
    ll ans = 0;
    // auto par = [&](auto self, int n)
    // {
    //     if (p[n] == n)
    //     {
    //         return n;
    //     }
    //     return self(self, p[n]);
    // };
    vector<int>d(n+1);
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            int z = abs(ent[i].first - ent[j].first) + abs(ent[i].second - ent[j].second);
            mini=min(z,mini);
            
        }
        d[i] = mini;
        for (int j = 0; j < i; j++)
        {
            int z = abs(ent[i].first - ent[j].first) + abs(ent[i].second - ent[j].second);
            if(d[i] > z)d[i] = z;
            
        }
    }
    for(int i =0;i <n;i++)
    {
        ans+=2*d[i];
    }
    // int cnt =0;
    // sort(all(q));
    // reverse(all(q));
    // while (q.size())
    // {
    //     auto [c, e] = q.back();
    //     q.pop_back();
    //     auto k = par(par, e.first);
    //     auto l = par(par, e.second);
    //     if (k != l)
    //     {
    //         cnt++;
    //         if (sz[k] < sz[l])
    //         {
    //             p[k] = l;
    //             sz[l] += sz[k];
    //         }
    //         else
    //         {
    //             p[l] = k;
    //             sz[k] += sz[l];
    //         }
    //         ans += 2 * c;
    //     }
    //     if(cnt == n-1)break;
    // }
    cout << ans << "\n";
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