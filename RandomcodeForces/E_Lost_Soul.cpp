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
    map<ll,ll>mpa,mpb;
    ll ans =0;
    vector<ll>botha(n+5),bothb(n+5);
    for(ll i = n-1;i>=0;i--)
    {
        mpa[a[i]] = max(mpa[a[i]],i);
        mpb[b[i]] = max(mpb[b[i]],i);
        botha[a[i]]|= (i%2) ^ (mpa[a[i]]%2);
        bothb[b[i]]|= (i%2) ^ (mpb[b[i]]%2);        
        if((mpa.count(b[i]) && ((mpa[b[i]] - i)%2 == 0)) || botha[b[i]])
        {
            ans = max(ans,i+1);
        }
        
        if((mpb.count(a[i]) &&((mpb[a[i]] - i)%2 == 0)) || bothb[a[i]])
        {
            ans = max(ans,i+1);
        }
        if((mpb[b[i]] - i)%2 == 1 || bothb[b[i]])
        {
            ans = max(ans,i+1);
        }
        if((mpa[a[i]] - i)%2 == 1 || botha[a[i]])
        {
            ans = max(ans,i+1);
        }
        // if(ans == 5){
        //     cout <<" ";
        // }
        if((mpa.count(b[i]) && ((mpa[b[i]] - i)%2 == 1)) && (mpa[b[i]] - i!=1))
        {
            ans = max(ans,i+1);
        }
        
        if((mpb.count(a[i]) &&((mpb[a[i]] - i)%2 == 1)) && (mpb[a[i]] - i!=1))
        {
            ans = max(ans,i+1);
        }
        //
        if((mpb[b[i]] - i)%2 == 0 && (mpb[b[i]] - i>1))
        {
            ans = max(ans,i+1);
        }
        if((mpa[a[i]] - i)%2 == 0 && (mpa[a[i]] - i>1))
        {
            ans = max(ans,i+1);
        }

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