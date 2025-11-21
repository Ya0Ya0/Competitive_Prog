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
ll const mod = 998244353;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = r * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return r;
}
void Solve()
{
    int n;
    cin >> n;
    read(p1, n);
    read(p2, n);
    int pf = 0, ps = 0, mx = 0, my = 0;
    for (int i = 0; i < n; i++)
    {
        if (mx < p1[i])
        {
            mx = p1[i];
            pf = i;
        }
        if (my < p2[i])
        {
            my = p2[i];
            ps = i;
        }
        
        ll ans=0,ex=0,cur=0;
        if (my > mx)
        {       
            cur = p1[i - ps]; 
            ex = my-cur;
            ans = elevar(2, ex)%mod;
            ans = (ans+1)%mod;    
            ans = (elevar(2,cur) * ans)%mod;
        }
        if (mx > my)
        {
            cur = p2[i - pf];
            ex = mx-cur;
            ans = elevar(2, ex)%mod;
            ans = (ans+1)%mod;    
            ans = (elevar(2,cur) * ans)%mod;
        }
        if (mx == my)
        {
            if (p2[i - pf] >= p1[i - ps])
            {
                cur = p2[i - pf];
                ex = mx-cur;
                ans = elevar(2, ex)%mod;
                ans = (ans+1)%mod;    
                ans = (elevar(2,cur) * ans)%mod;
               
            }else{
                cur = p1[i - ps];
                ex = my-cur;
                ans = elevar(2, ex)%mod;
                ans = (ans+1)%mod;    
                ans = (elevar(2,cur) * ans)%mod;
            }
        }
        cout << ans <<" ";
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