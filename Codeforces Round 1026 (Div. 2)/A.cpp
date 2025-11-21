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
    sort(all(ent));
    vector<ll> cp = ent;
    ll ans = n - 1;
    priority_queue<ll> bi;
    priority_queue<ll, vector<ll>, greater<ll>> les;
    for (int i = 0; i < n; i++)
    {
        les.push(ent[i]);
        bi.push(ent[i]);
    }
    int ini = ent[0] % 2;
    map<ll, ll> s;
    ll cnt = 0;
    while (les.top() % 2 != bi.top() % 2)
    {

        bi.pop();

        cnt++;
    }
    ans = min(ans, cnt);
    cnt = 0;
    cp = ent;
    int st = 0;
    while (st < n && cp[st] % 2 == ini)
        st++;
    while (!bi.empty())
        bi.pop();
    for (int i = st; i < n; i++)
    {

        bi.push(ent[i]);
    }
    while (!bi.empty() && (ini + 1) % 2 != bi.top() % 2)
    {
        bi.pop();

        cnt++;
    }
    ans = min(ans, st + cnt);

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