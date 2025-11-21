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
    int n;cin >> n;
    vector<int>ent(n);
    map<int,vector<int>>mp;
    for(int i = 0; i < n; i++)
    {
        cin >> ent[i];
        mp[ent[i]].push_back(i+1);
    }
    ll ans = n*(n+1)/2;
    for(int i = 1; i <=3; i++)
    {
        int k = i+2 > 3?(i+2)%3 : i+2;
        int ini = mp[i].front(),end = mp[i].back();
        auto r = lower_bound(all(mp[k]),ini);
        if(r != mp[k].end() && *r > end )
        {
            if(lower_bound(all(mp[k]),ini) !=mp[k].begin())
            {
                auto l = *(lower_bound(all(mp[k]),ini)-1 );
                ans-= (ini - l) * (*r - end);
            }
            else{
                ans-= (ini) * (*r-end);
            }
        }
        else{
            r--;
            auto l = *r;
            ans-=(ini-l)*(n+1-end);
        }
    }
    cout << ans << "\n";
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