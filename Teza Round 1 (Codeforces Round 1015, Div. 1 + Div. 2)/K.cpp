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
    int n, d;
    cin >> n >> d;
    // read(ent,n);
    set<ll> st;
    string cur = "";
    map<char, ll> mp;
    mp['A'] = 0;
    mp['B'] = 0;
    mp['C'] = 0;
    ll hash = 1e9+7;
    ll mod = 1e15 + 9;
    auto dfs = [&](auto self, int nd, char par,ll curH,ll pw)
    {
        if (nd >= n)
        {
            st.insert(curH);
            return;
        }
        for (char c = 'A'; c <= 'C'; c++)
        {
            if (c == par && c != 'B')
                continue;
            if (nd >= 2 && c == 'B' && cur[nd - 1] == 'B' && cur[nd - 2] == 'B')
                continue;
            mp[c]++;
            cur.push_back(c);
            ll mx = 0, mn = LONG_LONG_MAX;
            for (auto [a, b] : mp)
                mx = max(mx, b), mn = min(mn, b);
            ll t = (mx - mn) - d;
            if (n - nd -1< t)
            {
                mp[c]--;
                continue;
            }
            
            cur.push_back(c);
            ll nh = (curH + c*pw)%mod;
            self(self, nd + 1, c,nh,(pw*hash) %mod);
            cur.pop_back();
            mp[c]--;
        }
    };
    dfs(dfs, 0, ' ',1,hash);
    cout << st.size();
}

int main()
{
    // freopen("input.txt", "r", stdin);
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