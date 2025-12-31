#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
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
void init(){};
void Solve()
{
    int n; 
    cin >> n;
    read(a,n);
    read(b,n);
    vector<pair<ll,ll>>pre(n+1),suf(n+1);
    pre[0] = {a[0],a[0]};
    suf[n-1] = {b[n-1],b[n-1]};
    for(int i =1;i < n;i++)
    {
        pre[i] = pre[i-1];
        pre[i].first = min(pre[i].first, a[i]);
        pre[i].second = max(pre[i].second, a[i]);
    }
    vector<pair<ll,ll>>rang;
    for(int i = n-2;i>=0;i--)
    {
        suf[i] = suf[i+1];
        suf[i].first = min(suf[i].first, b[i]);
        suf[i].second = max(suf[i].second, b[i]);
    }
    for(int i = 0;i < n;i++)
    {
        auto [mn,mx] = pre[i];
        auto [mn1,mx2] = suf[i];
        rang.push_back({min(mn,mn1),max(mx,mx2)});
    }
    sort(all(rang),[](pair<ll,ll>a,pair<ll,ll>b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    vector<pair<ll,ll>>grang;
    grang.push_back(rang.front());
    for(auto a : rang){
        if(a.first == grang.back().first )continue;
        while(!grang.empty() && a.second <= grang.back().second){
            grang.pop_back();
        }
        grang.push_back(a);
    }
    ll ans =0;
    ll prev = 0;
    for(int i =0;i < grang.size();i++)
    {
        auto [mn,mx] = grang[i];
        ans+= (mn-prev)*(2*n-mx+1);
        prev = mn;
    }
    cout << ans <<"\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}