#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
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
    ll n, k;
    cin >> n >> k;
    read(ent, n);
    sort(all(ent));
    auto ck = [&](ll mid) -> bool
    {
        ll rem = k;
        for (int i = 0; i < n; i++)
        {
            if (ent[i] < mid)
                --rem;
            else
            {
                ll cur = ent[i];

                if (cur == mid)
                    continue;
                ll remin = cur - mid * 3;
                if (remin >= mid)
                {
                    continue;
                }
                rem--;
            }
        }
        if (rem >= 0)
            return true;
        return false;
    };
    ll l = 1,
       r = *max_element(all(ent)) + 1;
    vector<int> pre(r + 5);
    for (int i = 0; i < n; i++)
    {
        ll cur = ent[i];
        for (int j = 1; j * j <= cur; j++)
        {
            if (ent[i] % j == 0)
            {
                if (j > ent[i] / 4)
                {
                    pre[j]++;
                    pre[j +1]--;
                    
                }
                if(j*j != ent[i] && ent[i]/j > ent[i]/4)
                {
                    
                    pre[ent[i]/j]++;
                    pre[ent[i]/j + 1]--;
                }
            }
        }  
        ll kk = ent[i] / 4;
        if(kk < 1)continue;
        pre[1]++;
        if (kk)
            pre[kk + 1]--;
        else
            pre[2]--;
    }
    ll ans = 0;
    for (ll i = 1; i < r; i++)
    {
        pre[i] = pre[i] + pre[i - 1];
        if (pre[i] + k >= n)
        {
            ans = max(ans, i);
        }
    }
    cout << ans << "\n";
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