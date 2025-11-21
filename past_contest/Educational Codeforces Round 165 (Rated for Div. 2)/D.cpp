#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll,ll>, vector<pair<ll,  ll>>, greater<pair<ll,ll>>>
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
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n), b;
    for (auto &A : a)
        cin >> A.first;
    for (auto &A : a)
        cin >> A.second;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first < a[i].second)
        {
            b.push_back(a[i]);
        }
    }
    sort(all(b), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.second > b.second; });
    ll pr = 0;
    ll ans = 0;
    priority_queue<pair<ll,ll>> p;
    for (int i = 0; i < b.size(); i++)
    {
        if(i >= k)
            pr += b[i].second;
        else{
            p.push(b[i]);
        }
        pr -= b[i].first;
    }
    ans = pr;
    for (int i = k; i < b.size(); i++)
    {
        if(!p.empty() )
        {
            pr+=p.top().first;
            pr-= b[i]. second;
            p.pop();
            p.push(b[i]);
        }
        else break;
        
        ans = max(ans,pr);
    }   
    if (ans < 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
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