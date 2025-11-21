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
void Solve()
{
    int n; 
    cin >> n;
    // read(ent,n);
    vector<pair<ll, ll>> ent(n);

    for (auto &e : ent)
    {
        cin >> e.first >> e.second;
    }
    vector<pair<ll, ll>> cpy(ent);
    vector<tuple<ll, ll, ll>> ope(n);
    for(int i=0;i <n;i++)
    {
        ope[i] = {ent[i].first, ent[i].second, i};
    }
    sort(all(ope));
    vector<pair<ll,ll>>ord(n);
    for(int i =0;i<n;i++)
    {
        // ope[i].first = get<0>(ope[i]);
        if(i <n/2)
            ord[get<2>(ope[i])].first = 1;
        else
            ord[get<2>(ope[i])].first = 2;
    }
    sort(all(ope), [](const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b) {
        return get<1>(a) < get<1>(b);
    });
    for(int i =0;i<n;i++)
    {
        // ope[i].first = get<0>(ope[i]);
        if(i <n/2)
            ord[get<2>(ope[i])].second = 1;
        else
            ord[get<2>(ope[i])].second = 2;
    }
    vector<pair<ll, ll>> l,r;
    for(int i =0;i<n;i++)
    {
        if(ord[i].first == 1 )
        {
            l.push_back({ent[i].second,i});
        }
        else 
        {
            r.push_back({ent[i].second,i});
        }
    }
    sort(all(l));
    sort(all(r));
    vector<pair<ll,ll>> ans(n/2);
    ll sum =0;
    for(int i =0;i<n/2;i++)
    {
        ans[i].first = l[i].second;
        ans[i].second = r[n/2-i-1].second;
        sum+=abs(cpy[l[i].second].first -cpy[r[n/2-i-1].second].first);
        sum+=abs(cpy[l[i].second].second -cpy[r[n/2-i-1].second].second);
    }
    for(int i =0;i<n/2;i++)
    {
        cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
    }
    // cout << sum << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}