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
ll c = 5001;
void Solve()
{
    int n,m;cin >> n >> m;
    
    set<pair<ll,ll>>seg;
    for(int i =0;i <m;i++)
    {
        ll l,r;cin >> l >> r;
        seg.insert({l,r});
    }
    int cnt;cin >> cnt;
    vector<int>q(cnt);
    for(int i =0; i < cnt;i++)
    {
        cin >> q[i];
    }
    auto ck = [&](int v)
    {
        vector<int>pre(n+1);
        for(int i =0; i < v;i++)
        {
            pre[q[i]]++;
        }
        for(int i =1;i <=n;i++)
        {
            pre[i] += pre[i-1];
        }
        for(auto [l,r] : seg)
        {
            ll sz = r - l +1;
            if(pre[r] - pre[l-1] > sz/2)
            {
                return true;
            }
        }
        return false;
    };
    ll l = 0,r = cnt+1;
    while(r > l)
    {
        int mid = (l+r)/2;
        if(mid == cnt+1)break;
        if(ck(mid))
        {
            r = mid;
        }
        else l = mid+1;
    }
    cout << (r == cnt+1?-1 : r) << '\n';
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