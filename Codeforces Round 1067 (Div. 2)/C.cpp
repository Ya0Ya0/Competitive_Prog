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
const ll bg = LONG_LONG_MAX - 50;
ll inc = 1e9;
void Solve()
{
    ll n, k;
    cin >> n >> k;
    read(a, n);
    read(b, n);
    for (auto &bb : b)
        bb = abs(bb);
    // for(auto &aa : a)aa+=inc;
    vector<ll> pre(n + 2, 0), mxx(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i - 1];

        pre[i] = max(pre[i], a[i - 1]);
    }
    for (int i = n; i > 0; i--)
    {
        suf[i] = suf[i + 1] + a[i - 1];

        suf[i] = max(suf[i], a[i - 1]);
    }
    ll ans = -bg;
    // for(int i =n;i >0;i--)
    // {
    //     // mxx[i] = max(mxx[i+1],pre[i]);
    //     mxx[i] = max(mxx[i+1],pre[i]);
    //     if(pre[i] < 0)mxx[i] = pre[i];
    //     ans = max(ans,mxx[i]);
    // }

    for (ll i = 1; i <= n; i++)
    {
        // ans = max(ans,mxx[i]+b[i-1]);
        ans = max(pre[i], ans);
        ans = max(suf[i], ans);
        if (k & 1)
        {
            ans = max(ans, a[i - 1] + b[i - 1]);

            ans = max(ans, pre[i - 1] + +a[i - 1] + b[i - 1] + suf[i + 1]);
            ans = max(ans, pre[i] + b[i - 1]);
            ans = max(ans, b[i - 1] + suf[i]);
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