#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
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
    ll n,k;cin >> n >> k;
    vector<ll>ent(n),md(n);
    for(auto &e : ent)cin >> e;
    sort(all(ent));
    ll ans = ent.back();
    for(int i =0; i <n;i++)
    {
        md[i] = (ent.back() - ent[i])%(k*2);
    }
    ll mx = LONG_LONG_MAX;
    sort(all(md));
    ll add = 0;
    for(int i =0; i <n;i++)
    {
        if(md[i] < k)
            mx = min(mx, k-md[i]-1);
        else{
            if(k*2 - md[i] > mx)
            {
                cout << -1 << "\n";return;
            }
            else{
                add = max(add,k*2 - md[i]);
            }
        }
    }
    cout << ans + add << "\n"; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}