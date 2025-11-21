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
    ll inf = 1e9 + 7;
    ll n, m;
    cin >> n >> m;
    // read(ent,n);
    vector<vector<ll>> mat(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    ll r, c;
    cin >> r >> c;
    vector<string> adj(r);
    for (ll i = 0; i < r; i++)
        cin >> adj[i];
    vector<vector<bool>> vis(r, vector<bool>(c));
    struct mov
    {
        ll dir;
        vector<mov> v;
    };
    auto dfs = [&](ll x, ll y, ll dir, auto self) -> mov
    {
        vis[x][y] = true;
        vector<pair<ll, ll>> d{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        mov res;
        res.dir = dir;
        ll ndir = 0;
        for (auto [a, b] : d)
        {
            ll nx = x + a;
            ll ny = y + b;
            if (nx >= 0 && ny >= 0 && nx < r && ny < c && !vis[nx][ny] && adj[nx][ny]=='#')
            {
                res.v.push_back(self(nx, ny, ndir, self));
            }
            ndir++;
        }
        return res;
    };
    mov temp;
    bool out = 0;
    for (ll i = 0; i < r; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            if (adj[i][j] == '#')
            {
                temp = dfs(i, j, -1, dfs);
                out = 1;
            }
            if(out)break;
        }if(out)break;
    }
    auto ck = [&](mov t, ll i, ll j, ll rot, auto self) -> ll
    {
        vector<pair<ll, ll>> d{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        ll r = mat[i][j];
        for (auto mv : t.v)
        {
            ll ni = i + d[(mv.dir + rot) % 4].first;
            ll nj = j + d[(mv.dir + rot) % 4].second;
            if (ni >= 0 && nj >= 0 && ni < n && nj < m)
            {
                r += self(mv, ni, nj, rot, self);
            }
            else
            {
                return inf;
            }
        }
        return r;
    };
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += mat[i][j];
        }
    }
    ll Fr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int z = 0; z < 4; z++)
            {
                ll ans = ck(temp, i, j, z, ck);
                Fr = max(Fr, sum - ans);
            }
        }
    }
    cout << Fr << "\n";
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