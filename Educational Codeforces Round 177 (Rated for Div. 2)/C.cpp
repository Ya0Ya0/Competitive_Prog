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
    int n;
    cin >> n;
    read(ent, n);
    read(op, n);
    ll ans = 0;
    vector<ll> nw(n+1);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        mp[i] = ent[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll cur = op[i];
        if (nw[op[i]] == op[i])
        {
            cout << ans << " ";
            continue;
        }
        if(mp[cur - 1] == cur)
        {
            ans++;
        }
        while (mp[cur - 1] != cur)
        {
            ll z = mp[cur - 1];
            mp[cur - 1] = cur;
            nw[cur] = cur;
            cur = z;
            ans+=1;
        }
        cout << ans << " ";
    }
    cout << "\n";
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