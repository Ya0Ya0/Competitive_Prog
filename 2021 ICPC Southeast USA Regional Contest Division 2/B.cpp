#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)      \
    vector<double> name(cnt); \
    for (auto &e : name)     \
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
    ll n;
    cin >> n;
    read(ent, n);
    ll mx = pow(2, (n + 1));
    vector<double> pr(mx+5);
    set<ll>a{1,2},b{2,3};
    // a = a.merge(b.begin(),b.end());
    for (int i = 0; i < mx; i++)
    {
        if (__builtin_popcountl(i) > 2)
        {
            double alla =1,allb =1; 
            for (int j = 0; j < n; j++)
            {
                if ((1LL << j) & i)
                {
                    alla*=ent[j];
                    allb*=(1-ent[j]); 
                }
            }
            double tt =0, expect =0,cur;
            for (int j = 0; j < n; j++)
            {
                if ((1LL << j) & i)
                {
                    cur = alla/ent[j]*(1-ent[j]) + allb/(1-ent[j])*ent[j];
                    tt += cur;
                    expect += cur * pr[i^(1LL << j)]; 
                }
            }
            pr[i] = (1 + expect) / tt;
        }
    }
    cout <<fixed << setprecision(7) <<  pr[(1LL << n) -1] <<"\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}