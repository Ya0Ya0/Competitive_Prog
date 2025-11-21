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
    ll n,k;
    cin >> n >> k;
    vector<ll>ent(n);
    priority_queue<pair<ll,ll>>prq;
    for(int i = 0; i < n; i++)
    {
        cin >> ent[i];
        prq.push({ent[i],i});
    }
    ll l = n-1,r = 0,sum = 0;
    k-=2;
    if(k == 0)
    {
        sort(all(ent));
        cout << ent[n-1] + ent[n-2] << "\n";return;
    }
    while(k--)
    {
        auto cur = prq.top();
        prq.pop();
        if(cur.second == 0 || cur.second == n-1)
        {
            k++;continue;
        }
        sum+=2*cur.first;
        l = min(l,cur.second);
        r = max(r,cur.second);
    }
    ll v = 0;
    for(int i = 0; i < l;i++)
    {
        v = max(v,ent[i]);
    }
    sum+=v;v= 0;
    for(int i = n-1; i > r;i--)
    {
        v = max(v,ent[i]);
    }
    sum+=v;
    cout << sum << "\n";
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