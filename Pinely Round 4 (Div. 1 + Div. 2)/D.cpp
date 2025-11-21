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
vector<ll>pr;
ll mx = 131100*2;
vector<ll>ans(mx);
void Solve()
{
    int n;cin >> n;
    ll mxx = 1;
    for(int i = 1; i <=n; i++)
    {
        mxx = max(mxx,ans[i]);
    }
    cout << mxx <<"\n";
    for(int i = 1; i <=n; i++)
    {
        cout << ans[i] <<" ";
    }
    cout <<"\n";

}

vector<vector<ll>>g(mx);
int main()
{
    vector<bool> cr(mx);
    
    for (ll i = 2; i <= mx; i++)
    {
        if (!cr[i])
        {
            pr.push_back(i);
            for (ll j = i; j * i <= mx; j++)
            {
                cr[i * j] = 1;
            }
        }
    }
    map<ll,set<ll>>mp;
    
    ll mxx = 0;
    for(int i = 1; i <=mx; i++)
    {
        ll mini = mx;
        while(mp[i].count(mini))mini++;
        ans[i] = mini;
        mxx = max(ans[i],mxx);
        ll z = lower_bound(all(pr),i)-pr.begin();
        for(ll k = z; k < pr.size();k++)
        {
            
            
            mp[pr[k]^i].insert(ans[i]);
            
        }
    }
    // for(int i = 1; i <= mx; i++)
    // {
    //     for(int j = 1+1; i <= mx; j++)
    //     {
    //         if(!cr[i^j])
    //         {
    //             g[i].push_back(j);
    //             g[j].push_back(i);
    //         }
    //     }
    // }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}