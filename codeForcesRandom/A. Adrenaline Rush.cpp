#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
#define read(name, n)    \
    vector<ll> name(n);  \
    for (auto &e : name) \
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
long long elevar(long long a, long long b, ll c = LONG_LONG_MAX-5)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a)%c;
        a = (a * a)%c;
        b /= 2;
    }
    return r;
}

void Solve()
{
    ll n;
    cin >> n ;
    read(ent, n);
    for(auto &e : ent)e--;
    vector<int>cur(n);
    iota(all(cur),0);
    vector<pair<int,int>>ans;
    for(int i =n-1;i >=0;i--)
    {
        int pos = 0;
        for(int j =0;j < n;j++)
        {
            if(cur[j] == ent[i]){pos = j;break;}
        }
        for(int j =pos-1;j >=0 ;j--)
        {
            ans.push_back({cur[j+1],cur[j]});
            swap(cur[j],cur[j+1]);
        }
        for(int j =0;j < i ;j++)
        {
            ans.push_back({cur[j+1],cur[j]});
            swap(cur[j],cur[j+1]);
        }
    }
    cout << ans.size() <<"\n";
    for(auto [a,b] : ans)cout << a+1 << " " << b+1 << "\n"; 

}
// 1 2 3
// 2 3 1
void init()
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}