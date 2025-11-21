#include"bits/stdc++.h"
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
const ll MAX = (2 << 19)-1; 
vector<vector<pair<int,int>>>seen(MAX);
void Solve()
{
    int n;cin >> n;
    vector<ll>ent(n);
    set<pair<set<int>,long>>v;
    for(int i =0;i <n;i++)cin>> ent[i];
    ll ans = 0;
    for(int i =0;i <n;i++)
    {
        for(int j =i+1;j < n;j++)
        {
            long z = ent[i]^ent[j];
            seen[z].push_back({i,j});
            if(z == 0)continue;
            if(seen[z].size() > 1)
            {
                for(int k =0;k <seen[z].size()-1;k++)
                {
                    pair<set<int>,long>cur = {{i,j,seen[z][k].first,seen[z][k].second},z};
                    set<int>ck = {i,j,seen[z][k].first,seen[z][k].second};
                    if(v.find(cur)!=v.end() || ck.size()!=4)
                    {
                        continue;
                    }
                    ans+=8;
                    v.insert(cur);
                }
                
            }
        }
    }
    cout << ans << "\n";
    for(int i =0;i <n;i++)
    {
        for(int j =i+1;j < n;j++)
        {
            long z = ent[i]^ent[j];
            seen[z].clear();            
        }
    }
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