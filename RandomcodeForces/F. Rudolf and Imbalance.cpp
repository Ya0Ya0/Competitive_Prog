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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), mv(m), kv(k);
    for (auto &A : a)
        cin >> A;
    for (auto &A : mv)
        cin >> A;
    for (auto &A : kv)
        cin >> A;
    sort(all(a));
    sort(all(mv));
    sort(all(kv));
    ll max1 = -1, max2 = -1;
    ll l , r;
    for (int i = 1; i < n; i++)
    {
        max1 = max(max1, a[i] - a[i - 1]);
        if (max1 > max2)
        {
            swap(max1, max2);
            l = a[i-1];
            r = a[i];
        }
    }
    if(n == 1)
    {
        ll t = a[0];
        ll curAns = 1e9 + 7;
        for(int i = 0; i < m; i++)
        {
            ll rem = t - mv[i];
            auto f = lower_bound(all(kv), rem);
            ll lb=-1,rb=-1;
            if(f!=kv.end())rb = *f;
            if(f!=kv.begin())lb = *(f-1);
            if(rb!=-1)
            {
                curAns = min(curAns, abs(t - (mv[i] + rb)));
            }
            if(lb!=-1)
            {
                curAns = min(curAns, abs(t - (mv[i] + lb)));
            }           

        }
        cout << curAns << "\n";
    }
    else if(n == 2)
    {
        ll t = (l+r)/2;
        ll curAns = max2;
        for(int i = 0; i < m; i++)
        {
            ll rem = t - mv[i];
            auto f = lower_bound(all(kv), rem);
            ll lb=-1,rb=-1;
            if(f!=kv.end())rb = *f;
            if(f!=kv.begin())lb = *(f-1);
            if(rb!=-1)
            {
                ll z = max((mv[i] + rb) - l, r - (mv[i] + rb));
                curAns = min(curAns, z);
            }
            if(lb!=-1)
            {
                ll z = max((mv[i] + lb) - l, r - (mv[i] + lb));
                curAns = min(curAns, z);
            }  
        }
        cout << curAns << "\n";
    }
    else{
        ll t = (l+r)/2;
        ll curAns = max2;
        for(int i = 0; i < m; i++)
        {
            ll rem = t - mv[i];
            auto f = lower_bound(all(kv), rem);
            ll lb=-1,rb=-1;
            if(f!=kv.end())rb = *f;
            if(f!=kv.begin())lb = *(f-1);
            if(rb!=-1)
            {
                ll z = max((mv[i] + rb) - l, r - (mv[i] + rb));
                curAns = min(curAns, z);
            }
            if(lb!=-1)
            {
                ll z = max((mv[i] + lb) - l, r - (mv[i] + lb));
                curAns = min(curAns, z);
            }  
        }
        curAns = max(max1,curAns);
        
        cout << curAns << "\n";
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