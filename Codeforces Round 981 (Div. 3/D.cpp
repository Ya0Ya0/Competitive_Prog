#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

const ll big = 1e5+1;
#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : ent)   \
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
    ll n;
    cin >> n;
    read(ent, n);
    // for(auto e : ent)cout << e <<  " ";
    // for(auto &e : ent)e+=big;
    map<ll, ll> seen;
    seen[0] = -1;
    vector<pair<ll, ll>> segs;
    ll cur = 0;
    for (ll i = 0; i < n; i++)
    {
        cur += ent[i];

        if (ent[i] == 0)
        {
            segs.push_back({i, i});
        }

        if (seen.count(cur))
        {
            
            segs.push_back({seen[cur]+1, i});
        }
        
        
        seen[cur] = i;
        
    }
    if (segs.size() == 0)
    {
        cout << 0 << "\n";
        return;
    }
    sort(all(segs), [](auto a, auto b)
         {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second; });
    vector<pair<ll, ll>> t;
    t.push_back(segs[0]);
    // for(int i =1;i < segs.size();i++)
    // {
    //     if(segs[i].first == t.back().first)
    //     {
    //         if(t.back().second < segs[i].second)
    //         {
    //             t.pop_back();
    //             t.push_back(segs[i]);
    //         }
    //     }
    //     else{
    //         t.push_back(segs[i]);
    //     }
    // }

    ll lst = -1, ans = 0;
    for (ll i = 0; i < segs.size(); i++)
    {
        if (segs[i].first > lst)
        {
            lst = segs[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
}
// 1 1 1 1 2 2 2 2 1 1 1 1  2 2 3 3 3 2 1 1 1
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