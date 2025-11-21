#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : ent)   \
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
    int n;
    cin >> n;
    read(ent, n);
    ll l = 0, r = 1e18;
    auto ck = [&](ll mid)
    {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            while (ent[i + 1] - ent[i] > mid)
            {
                ent[i] = ent[i] + mid;
                cnt++;
            }
            while (i < n - 1 && ent[i + 1] - ent[i] <= mid)
            {
                i++;
            }
        }
        return cnt<=1;
    };
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (ck(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    // ll ans =1e18;
    // vector<ll>pre(n);
    // pre[0] = ent[1]-ent[0];
    // pre[n-1] = ent[n-1]-ent[n-2];
    // ll tans =max(pre[0],pre[n-1]);
    // for(int i =1;i <n-1;i++)
    // {
    //     pre[i] = min(ent[i]-ent[i-1], ent[i+1]-ent[i]);
    //     tans = max(tans,pre[i]);
    // }
    // map<ll,ll>mp;
    // for(auto p : pre)mp[p]++;
    // for(int i =0;i <n;i++)
    // {
    //     if(i < n-1 && pre[i] == pre[i+1] && pre[i] == tans && mp[pre[i]] == 2)
    //     {
    //         pre[i] = pre[i]/2;
    //         pre[i+1] == (pre[i]+1)/2;
    //     }
    //     if(pre[i] == tans && mp[pre[i]] == 1)
    //     {

    //     }
    // }

    // for(int i =1;i <n-1;i++)
    // {
    //     int lst = 0;
    //     ll curans = 1;
    //     for(int j =1;j <n;j++)
    //     {
    //         if(lst == i)
    //         {
    //             lst+=2;
    //         }
    //         if(j == i)continue;
    //         curans = max(curans,ent[j]-ent[lst]);
    //         lst++;
    //     }
    //     ans = min(ans,curans);
    // }
    // ll curans = 1;
    // for(int i =2;i <n;i++)
    // {
    //    curans=  max(ent[i]-ent[i-1],curans) ;
    // }
    // ans = min(ans,curans);
    // curans = 1;
    // for(int i =1;i <n-1;i++)
    // {
    //    curans=  max(ent[i]-ent[i-1],curans) ;
    // }
    // ans = min(ans,curans);
    // cout << ans << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}