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
    int r, c;
    cin >> r >> c;
    // read(ent,n);
    ll x, y, xe, ye;
    cin >> x >> y >> xe >> ye;
    vector<string> adj(r);
    for (auto &e : adj)
        cin >> e;
    vector<vector<vector<bool>>> vis(r, vector<vector<bool>>(c, vector<bool>(4)));
    bool ok = false;
    // 1 R
    // 2 D
    // 3 L
    // 4 U
    auto val = [&](pair<ll, ll> v, ll dir) -> bool
    {
        if (v.first < 0 || v.second < 0 || v.first >= r || v.second >= c)
            return false;        
        if (adj[v.first][v.second] == '1')
            return false;
        return true;
    };
    auto dfs = [&](pair<ll, ll> v, ll dir, auto self)
    {
        if (!val(v, dir))
            return;
        if (vis[v.first][v.second][dir])
            return;
        vis[v.first][v.second][dir] = true;
        pair<ll, ll> inc{0, 0};
        if (dir == 0)
            inc = {0, -1};
        if (dir == 1)
            inc = {1, 0};
        if (dir == 2)
            inc = {0, 1};
        if (dir == 3)
            inc = {-1, 0};
        pair<ll, ll> nx = {v.first + inc.first, v.second + inc.second};
        if (dir == 3)
            inc = {0, -1};
        if (dir == 0)
            inc = {1, 0};
        if (dir == 1)
            inc = {0, 1};
        if (dir == 2)
            inc = {-1, 0};
        pair<ll, ll> nx2 = {v.first + inc.first, v.second + inc.second};
        if (val(nx, (dir - 1 + 4) % 4))
        {
            self(nx, (dir - 1 + 4) % 4, self);
        }
        else if (val(nx2, dir))
        {
            self(nx2, dir, self);
        }
        else
        {
            self(v, (dir + 1) % 4, self);
        }
        if (v.first == xe - 1 && v.second == ye - 1)
            ok = true;
    };
    dfs({x - 1, y - 1}, 0, dfs);
    cout << (ok ? 1 : 0) << "\n";
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