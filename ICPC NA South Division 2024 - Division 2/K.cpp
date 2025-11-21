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
    int n, m, ope;
    const ll MAXN = 1e9+5;
    // bitset<MAXN>b;
    cin >> n >> ope >> m;
    read(ent, n);
    vector<pair<char, ll>> vope(ope);
    for (auto &[a, b] : vope)
        cin >> a >> b;
    unordered_map<ll, ll,custom_hash> cnt;
    for (auto e : ent)
        cnt[e]++;
    ll ini = ent[m - 1];
    if (cnt[ini] == 1)
    {
        cout << "0\n";
        return;
    }
    queue<ll> q;
    q.push(ini);
    unordered_map<ll, ll,custom_hash> seen;
    unordered_map<ll, pair<ll, int>,custom_hash> par;
    ll ans = -1;
    bool out = false;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop(); 

        int opn = 0;
        for (auto [a, b] : vope)
        {
            ll num = 0;
            if (a == '+')
            {
                num = cur + b;
            }
            if (a == '-')
            {
                num = cur - b;
            }
            if (a == '*')
            {
                num = cur * b;
            }
            if (a == '/')
            {
                num = cur / b;
            }
            if (num >= 0 && !seen.count(num))
            {
                q.push(num);
                seen[num]++;
                if (!par.count(num))
                    par[num] = {cur, opn};
                if (!cnt[num])
                {
                    ans = num;
                    out = true;
                    break;
                }
            }
            opn++;
        }
        if(out)break;
    }
    vector<int> fans;
    while (ans != ini)
    {
        fans.push_back(par[ans].second);
        ans = par[ans].first;
    }
    reverse(all(fans));
    cout << fans.size() << "\n";
    for (auto e : fans)
    {
        cout << e + 1 << " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);ccccccc
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}