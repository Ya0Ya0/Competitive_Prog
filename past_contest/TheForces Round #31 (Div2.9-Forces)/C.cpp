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
    ll n;
    cin >> n;
    vector<vector<ll>> t(n);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        t[--a].push_back(--b);
        //t[b].push_back(a);
    }
    auto bfsf = [&](ll node)
    {
        vector<bool> vis(n);
        vector<ll> dis(n);
        dis[node] = 0;
        queue<ll> q;
        q.push(node);
        ll mx = node;
        while (!q.empty())
        {
            ll cur = q.front();
            q.pop();
            if (vis[cur])
                continue;
            vis[cur] = true;
            if (dis[cur] > dis[mx])
                mx = cur;
            for (auto e : t[cur])
            {
                if (vis[e])
                    continue;
                q.push(e);
                dis[e] = dis[cur] + 1;
            }
        }
        return mx;
    };
    auto bfs = [&](auto &self,ll node)->pair<ll,ll>
    {
        pair<ll,ll> d = {0,0};
        for(auto e : t[node])
        {
            auto z = self(self,e);
            d.first++;
        }
        d.second+=t[node].size()*(t[node].size()+1)/2 - 1;
        return d;
    };
    auto far = bfsf(0);
    auto d = bfs(bfs,far);
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}