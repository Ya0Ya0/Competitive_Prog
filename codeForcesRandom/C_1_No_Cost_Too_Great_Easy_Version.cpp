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
const ll MAXN = 2e5 + 5;
vector<vector<int>> pdiv(MAXN);
void init()
{
    for (int i = 2; i<= MAXN; i++)
    {
        if (pdiv[i].empty())
        {            
            for (int j = i; j <= MAXN; j += i)
            {
                pdiv[j].push_back(i);
            }
        }
    }
};
void Solve()
{
    int n;
    cin >> n;
    read(ent, n);
    read(_, n);
    map<int,int>mp;
    for(auto e : ent)
        for(auto divi : pdiv[e]){
            mp[divi]++;
            if(mp[divi] > 1){
                cout << 0 <<"\n";return;
            }
        }
    if(mp[2]){
        cout << 1 <<"\n";return;
    }
    for(auto e : ent)
        for(auto divi : pdiv[e+1]){            
            if(mp[divi] == 1){
                cout << 1 <<"\n";return;
            }
        }
    cout << 2 <<"\n";return;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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