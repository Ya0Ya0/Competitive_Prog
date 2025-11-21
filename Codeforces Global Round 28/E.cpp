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
    int n, m;
    cin >> n >> m;
    // read(ent,n);
    vector<int> visn(2 * n);
    vector<int> vism(m);
    vector<vector<int>> cl(2 * n, vector<int>(m));
    auto dfs = [&](int nd)
    {
        stack<pair<ll, ll>> stk;
        stk.push({nd, 0});
        while (!stk.empty())
        {
            auto e = stk.top();
            stk.pop();
            if (e.second == 0)
            {
                visn[nd] = 1;
            }
            else
            {
                vism[nd] = 1;
            }

            auto z = e.second == 0 ? 2 * n : m;
            for (int i = 0; i < z; i++)
            {
                if (e.second == 0)
                {
                    if(vism[i] = 1)
                        cl[nd][i]++;
                }
                else
                {
                    if(visn[i] = 1)
                        cl[i][nd]++;
                }
            }
            if (e.second == 0)
            {
                visn[nd] = 2;
            }
            else
            {
                vism[nd] = 2;
            }
        }
    };
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