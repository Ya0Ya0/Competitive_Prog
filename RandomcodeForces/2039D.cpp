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
ll c = 5001;
ll mod = 1e9 + 7;
const ll MAXN = 1e5+5;
set<ll> cr[MAXN+5];
ll ans[MAXN+5];

void Solve()
{
    max({2,2});
    ll n,k;cin >> n >> k;
    vector<ll>ent(k),a(n);
    for(auto &e : ent)cin >> e;
    reverse(all(ent));

    for(int i =1;i <=n;i++)
    {
        if(ans[i] <= k)
        {
            a[i-1] = ent[ans[i]-1];
        }else{
            cout << -1 <<"\n";
            return;
        }
    }
    for(auto e : a)
    {
        cout << e <<" ";
    }
    cout << "\n";
}
void init()
{
    for(int i = 2;i < MAXN;i++)
    {
        ll cur =2;
        for(auto e : cr[i])
        {
            if(e==cur)cur++;
            else break;
        }
        ans[i] = cur;
        for(int j = 2;j*i < MAXN ;j++)
        {
            cr[i*j].insert(cur);
            
        }
    }
    ans[1]=1;
}
int main()
{
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