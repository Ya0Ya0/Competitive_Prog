#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
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
// ll count(ll aa, ll cnt)
// {
//     // ll aa = stoll(a);
//     // ll pw = pow(10,(a.length()+1) /2);
//     // ll ini = pow(10,(a.length()+1) /2);
//     ll ans = 0;
//     ll l = 0, r = sqrtl(aa + 20);
//     while (r - l > 1)
//     {
//         ll mid = r + l >> 1;
//         ll v = 0;

//         for (int i = 0; i <= cnt && v < aa; i++)
//         {
//             ll pw = pow(10, (ll)(log10(mid) + 1));
//             ll cur = mid;
//             v = v * pw + cur;
//         }
//         if (v < aa)
//         {
//             l = mid;
//         }
//         else
//         {
//             r = mid;
//         }
//     }
//     return l;
// }
ll const MX = 1e6 + 5;
ll const RMX = 1e15+5;
vector<ll>pr{1,2,3,6,4,5,7,8,9,10};
// vector<vector<ll>> ss(20, vector<ll>(MX));
set<ll>seen;
void init()
{
    
    for (auto k : pr)
    {
        for (int i = 1; i < MX; i++)
        {
            // ss[k][i] = ss[k][i - 1];
            ll cur = 0;

            for (int j = 0; j <= k; j++)
            {
                ll pw = pow(10, (ll)(log10(i) + 1));
                ll v = i;
                cur = cur * pw + v;
                if(cur > RMX)break;
            }
            if(cur > RMX)break;
            if(seen.count(cur))continue;
            seen.insert(cur);
            
            // ss[k][i] += cur;
        }
    }
    return;
}; // 24148522478
void Solve()
{
    ll a, b;
    ll ans = 0;
    set<pair<ll,ll>>s;
    seen.insert(0);
    ll mm = 0;
    while (cin >> a)
    {
        char _;
        cin >> _ >> b >> _;
        mm = max({mm,a,b});
        vector<pair<ll,ll>>rang;
        for (auto i : pr)
        {
            // ll aa = count(a, i), bb = count(b + 1, i);
            auto aa = seen.lower_bound(a);
            if(*aa >= a)aa = prev(aa);
            auto bb = seen.lower_bound(b);
            if(*bb > b)bb = prev(bb);
            // ll df = ss[i][bb] - ss[i][aa];
            // if (df)
            //     ans+=df;
            if(*aa < *bb)
                rang.push_back({*aa,*bb});
        }
        sort(all(rang));
        if(rang.empty())continue;
        vector<pair<ll,ll>>p{rang.front()};
        for(int i =1;i < rang.size();i++){
            auto [a,b] = p.back();
            p.pop_back();
            auto [cura,curb] = rang[i];
            while(b >= cura && p.size()){
                cura =a;
                a = p.back().first;
                b=p.back().second;
                p.pop_back();
            }
            p.push_back({cura,curb});
        }
        for(auto[a,b] : p)
        {
            auto it = seen.lower_bound(a+1);
            while(*it<=b){
                ans+=*it;
                it = next(it);
            }
        }
        // cout << a <<"\n";
    }
    // for(auto e : s)ans+=e;
    //33975850791
    //25466191202
    // cout << 'q';
    cout << ans;
}
/*
in a range a-b
count less than a and less than b+1 and sub them
length has to be pair start at length of a and end at length of b

*/

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
    return 0;
}