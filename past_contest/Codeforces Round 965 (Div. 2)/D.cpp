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
ll z = 0;
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    vector<ll> dis(n + 1, -1), ans(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<int> dp(n + 1, -1);
    auto dfs = [&](auto self, int v) -> void
    {
        queue<ll> q;
        q.push(v);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (auto e : g[cur])
            {
                if (dis[e] == -1)
                {
                    dis[e] = dis[cur] + 1;
                    q.push(e);
                }
            }

            if (cur < n && dis[cur + 1] == -1)
            {
                dis[cur + 1] = dis[cur] + 1;
                q.push(cur+1);
                
            }
        }        
    };
    dis[1] = 0;
    dfs(dfs, 1);

    for (int i = 1; i < n; i++)
    {
        for (auto e : g[i])
        {
            if (dis[i] + 1 < e - i)
            {
                ans[i + 1]++;
                ans[e - (dis[i] + 1)]--;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] += ans[i - 1];
    }
    // if(z == 589)
    // {
    //     for(int i = 0; i <= n; i++)
    //     {
    //         for(auto e : g[i])
    //         {
    //             cout << i << e;
    //         }
    //     }
    //     cout << "\n";return;
    // }
    for (int i = 1; i < n; i++)
    {
        if (ans[i] > 0)
        {
            cout << 0;
        }
        else
            cout << 1;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    
    while (tt--)
    {
        z++;
        Solve();
    }
}