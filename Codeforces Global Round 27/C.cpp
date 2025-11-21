#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : ent)   \
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
void Solve()
{
    int n;
    cin >> n;
    // read(ent,n);
    // for(auto e : ent)cout << e <<  " ";
    ll kk = __popcount(n);
    ll lst = 1 << (int)(log2(n));
    vector<ll> per(n + 1);
    iota(all(per), 0);
    //cout << kk << "\n";
    ll sec = 0;
    ll thrd = lst - 1;
    ll frth = 0;
    ll h = 1 << ((int)(log2(n))+1);
    for (int i = 31; i >= 0; i--)
    {
        ll t = sec;
        t |= (n & (1LL << i));
        if (__popcount(t) == kk )
        {
            frth = 1LL << i;
            break;
        }
        sec = t;
    }
    if (kk == 1)
    {
        sec = n - 1;
        thrd = sec-1;
        frth = 3;
        ll fifth =1;
        swap(per[n - 1], per[sec]);
        swap(per[n - 2], per[thrd]);
        swap(per[n - 3], per[frth]);
        swap(per[n - 4], per[fifth]);
        // cout << h-1 << "\n";
    }
    else if (n & 1)
    {
        swap(per[n - 1], per[sec]);
        swap(per[n - 2], per[thrd]);
        swap(per[n - 3], per[frth]);
        // cout << n << "\n";
    }
    else
    {
        ll fst = lst-1;
        sec = n;
        thrd = n-1;
        swap(per[n-2],per[thrd]);
        swap(per[n-1],per[n]);
        swap(per[n],per[fst]); 
        // cout << h-1 << "\n";
    }   
    ll ans =0; 
    for(int i =1;i<=n;i++)
    {
        if(i&1)
        {
            ans = ans&per[i];
        }
        else{
            ans = ans|per[i];
        }
    }
    cout << ans << "\n";
    for(int i =1;i <=n;i++)
    {
        cout << per[i]<< " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}