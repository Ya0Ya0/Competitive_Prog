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
    ll a,b;cin >> a >> b;
    vector<ll>ope;
    ll aux;
    for(int i =31;i >= 0;i--)
    {
        if(b&(1LL << i) && !(a&(1LL << i)))
        {
            cout << -1 <<"\n";return;
        }
        if(!(b&(1LL << i)) && (a&(1LL << i)))
        {
            break;
        }
        if((b&(1LL << i)) && (a&(1LL << i)))break;
    }
    aux= 0;
    bool on = 0;
    for(int i =31;i >=0;i--)
    {
        if(on && !(a&(1LL << i)))
        {
            aux |= (1LL << i);
            a |= (1LL << i);
        }
        if(a&(1LL << i))on = true;
    }
    ope.push_back(aux);
    aux =0;on = 0;
    for(int i =31;i >=0;i--)
    {
        if((a & (1LL<<i)) && !(b&(1LL << i)))
        {
            aux |= (1LL << i);
        }
    }
    ope.push_back(aux);
    ll ok = false;
    for(auto a : ope)
    {
        ok |= a!=0?1:0;
    }
    if(!ok)
    {
        cout << 0 <<"\n";return;
    }
    cout << ope.size() <<"\n";
    for(auto o : ope)cout << o <<" ";
    cout << "\n";
    // cout << a <<" ";
    // for(auto o : ope)
    // {
    //     a = a^o;
    //     cout << a <<' ';
    // }
    // cout <<"\n";
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