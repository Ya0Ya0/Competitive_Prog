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
const ll maxn = 1e5+20;
ll mod = 998244353;
vector<ll>factorial(maxn+5),inv(maxn+5);
void Solve()
{
    ll n;
    cin >> n ;   
    read(ent, n);
    int ch = 0;
    ll ans =1;
    for(int i = n;i >0;i--)
    {
        if(i*2 == n+1)ch++;
        else if ( i*2 <= n)ch+=2;
        if(ent[i-1] > ch){
            cout << 0 <<"\n";return;
        }
        if(ent[i-1]){
            ans = (ans * factorial[ch] * inv[ch-ent[i-1]] * inv[ent[i-1]])%mod;
            ch-=ent[i-1];
        }
    }
    if(ch){
        cout << 0 <<"\n";return;
    }
    cout << ans <<"\n";

}
void init()
{
    factorial[0] = 1;
    for(int i =1;i <=maxn;i++)
    {
        factorial[i] = (factorial[i-1] * i) % mod;
    }
    inv[maxn] = elevar(factorial[maxn],mod-2,mod);
    for(int i = maxn-1;i>=0;i--)
    {
        inv[i] = inv[i+1] * (i+1) %mod;
    }
    // inv[0] = inv[1];
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