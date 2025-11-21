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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> p(2 * n + 2, vector<pair<int, int>>(2 * m + 2));
    vector<vector<bool>> vis(2 * n + 2, vector<bool>(2 * m + 2));
    vector<vector<char>> g(2 * n + 2, vector<char>(2 * m + 2));
    ll count = 1;
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            cin >> g[i][j];
        }
    }
    auto parent = [&](pair<int, int> z, auto self) -> pair<int, int>
    {
        auto [i, j] = z;
        if (p[i][j].first == 0 && p[i][j].second == 0)
            return pair<int, int>{i, j};
        else
            return self(p[i][j], self);
    };
    queue<pair<int, int>> q;
    auto dfs = [&](int a, int b)
    {
        queue<pair<int, int>> q;
        q.push({a, b});
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            if (vis[i][j] || g[i][j] != '.')
                continue;
            vis[i][j] = true;
            if(!vis [i- 1][j])
            p[i - 1][j] = parent({a,b}, parent);
             if(!vis [i+ 1][j])
            p[i + 1][j] = parent({a,b}, parent);
             if(!vis [i][j-1])
            p[i][j - 1] = parent({a,b}, parent);
             if(!vis [i][j+1])
            p[i][j + 1] = parent({a,b}, parent);
            q.push({i - 1, j});
            q.push({i + 1, j});
            q.push({i, j + 1});
            q.push({i, j - 1});
        }
    };
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            if (g[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
            }
        }
    }
    vector<vector<bool>> vis2(2 * n + 2, vector<bool>(2 * m + 2));
    vector<pair<int, int>> v{{0, -2}, {-2, 0}, {2, 0}, {0, 2}};
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            if (g[i][j] == '.' && i%2== 0 && j%2 == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    ll a = i + v[k].first;
                    ll b = j + v[k].second;
                    if (a > 0 && a < 2 * n + 1 && b > 0 && b < 2 * m + 1)
                    {
                        if (parent({a, b}, parent) != parent({i, j}, parent))
                        {
                            p[parent({a,b},parent).first][parent({a,b},parent).second] = parent({i, j}, parent);
                            g[i + (a-i) / 2][j + (b-j) / 2] = '.';
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            cout << g[i][j];
        }
        if(i!=2 * n + 1)
            cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}