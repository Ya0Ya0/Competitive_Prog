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
    int n; 
    cin >> n;
    read(ent,n);
    vector<ll>pre(n+1);
    for(int i =0;i <n;i++)
    {
        pre[i+1] = pre[i] + ent[i];
    }
    ll sum = accumulate(ent.begin(), ent.end(), 0LL);
    for(int i =0;i <n;i++)
    {
        ll k =sum - ent[i];
        if(ent[i] > k)
        {
            cout << -1 << "\n";
            return;
        }
        if(pre[i+1]==sum - pre[i+1])
        {
            cout << 1 << "\n";
            for(int i =0;i < n;i++)
            {
                cout << ent[i] << " ";
            }
            cout << "\n";
            return;
        }
    }
    if(sum%2)
    {
        cout << -1 << "\n";
        return;
    }
    cout << 2 << "\n";
    auto k = ent.begin()- lower_bound(pre.begin(), pre.end(), sum/2);
    ll l = ent[k-1];
    ll r = sum - ent[k];
    
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