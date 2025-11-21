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
    // int n; 
    // cin >> n;
    // read(ent,n);
    // ll x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(y1 < x1)swap(x1,y1);
    if(y2 < x2)swap(x2,y2);
    if((x1 == 0 && y1 == 2024 && y2 == 2024 && x2 == 0) ||
        (x1 == 0 && y1 == 0 && y2 == 2024 && x2 == 2024) || 
            (x1 == 2024 && y1 == 2024 && y2 == 0 && x2 == 0)
    ){
        cout << 0 <<"\n";
        return;
    }
    vector<pair<int,int>>v{{0,0},{0,2024},{2024,2024},{2024,0}};
    for(auto [a,b]: v)
    {
        if((a == x1 && b == y1) ||(a == x2 && b == y2)  )
        {
            cout << 1 <<"\n";
            return;
        }
        // swap(x1,y1);
        // swap(x2,y2);
        // if((a == x1 && b == y1) ||(a == x2 && b == y2)  )
        // {
        //     cout << 1 <<"\n";
        // }
    }
    cout << 2 <<"\n";

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}