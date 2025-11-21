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
    ll n,k; 
    cin >> n >> k;
    vector<pair<ll, ll>> ent(n);
    for (auto &e : ent) cin >> e.first;
    for(auto &e : ent) cin >> e.second;
    map<ll, pair<ll,ll>> mp;
    vector<ll>r,l;
    bool end =0;
    for(ll i = 0;i<n;i++){
        if(ent[i].first > ent[i].second)swap(ent[i].first,ent[i].second);
        if( mp[ent[i].first].first || mp[ent[i].second].second || mp[ent[i].first].second || mp[ent[i].second].first)
        {
            end = 1;
            break;
        }
        mp[ent[i].first].first ++;
        mp[ent[i].second].second ++;        
    }
    ll cur =0;
    for(auto &e : mp)
    {
        cur += e.second.first;
        if(cur >=2 )
        {
            end=1;
            break;
        }
        cur -= e.second.second;
    }
    // read(ent,n);
    if(end){
        ll ans =0;
        for(int i =0;i<n;i++)
        {
            ans+=abs(ent[i].first - ent[i].second);
        }
        cout << ans << "\n";
        return;
    }
    // vector<pair<ll,ll>>aux;
    ll fans=0;
    for(ll i =0;i <n;i++)
    {
        // aux.push_back({min(ent[i].first, ent[i].second)*2,i});
        fans+= abs(ent[i].first - ent[i].second);
    }
    // sort(all(aux));
    ll ans = LONG_LONG_MAX;
    ll idx =-1;
    for(int i =0;i <n;i++)
    {
        l.push_back(ent[i].first);
        r.push_back(ent[i].second);
    }
    sort(all(l));
    sort(all(r));
    for(ll i=0;i <n;i++)
    {
        ll z =lower_bound(l.begin(), l.end(), r[i])-l.begin();
        if(z == l.size())continue;
        ll cur = 2*(l[z] - r[i]);
        if(cur < ans)
        {
            ans = cur;
            idx = i;
        }
    }
    // fans-= abs(ent[aux[idx].second].first - ent[aux[idx].second].second);
    // fans-= abs(ent[aux[idx+1].second].first - ent[aux[idx+1].second].second);
    // fans+=aux[idx+1].first -aux[idx].first;
    fans+=ans;
    cout << fans << "\n";
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