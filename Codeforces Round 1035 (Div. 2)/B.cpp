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
    ll x1,x2,y1,y2,n; 
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    
    read(ent,n);
    double dis = sqrtl((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    ll s =0;
    for(int i =0;i < n;i++)
    {
        s+=ent[i];
    }
    // ll s = accumulate(all(ent), 0LL);
    if(dis > s)
    {
        cout << "NO\n";
        return;
    }
    if(n ==0 && dis!=0)
    {
        cout << "NO\n";
        return;
    }
    if(n==1 && dis!=s)
    {
        cout << "NO\n";
        return;
    }
    auto istr = [&](ll x,ll y,double z)
    {
        if(x+y < z) return false;
        if(x+z < y) return false;
        if(y+z < x) return false;
        return true;
    };
    if(n==2 && (!istr(dis ,ent[0]*ent[0] , ent[1]*ent[1]) && abs(ent[0]-ent[1]) != dis))
    {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
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