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
void Solve()
{
    int n;cin >> n;
    vector<int>ent(n+1),pre(n+1),good(n+1);
    vector<int>one;
    ll ans =0;
    for(int i =1;i <=n;i++)cin >> ent[i],ans+=(ent[i]==1);
    for(int i =1;i <=n;i++)
    {
        if(ent[i] == 1 && ent[i-1] == 1)good[i]=1;
        if(i >1 && ent[i] == 1 && ent[i-2] == 1)good[i]=1;
    }
    for(int i =1;i <=n;i++)
    {
        pre[i] = pre[i-1] + (good[i] == 1);
       
    }
    good.push_back(good.back()+1);
    for(int i =1;i <=n;i++)
    {
        int ini = lower_bound(all(pre),pre[i]+1) - pre.begin();        
        //if(ini < i)ini = lower_bound(all(pre),pre[i]+1) - pre.begin();
        if(ini == n+1)continue;
        if(ini - i < 2 && ent[i] == 0)ini = lower_bound(all(pre),pre[i]+2) - pre.begin();
        ans+=n - ini+1;
    }
    cout << ans <<"\n";
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