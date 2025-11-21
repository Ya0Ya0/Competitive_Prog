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
    string s;
    getline(cin, s);
    istringstream is(s);
    int n;
    stack<int> stk;
    vector<vector<int>> g(200000);
    int prev = -1;
    int iniv = -1;
    vector<int> p;
    while (is >> n)
    {
        if(iniv == -1)iniv = n;
        if (prev != -1)
        {
            g[prev - 1].push_back(n - 1);
        }
        p.push_back(n);
        prev = n;
    }
    if (!stk.empty())
    {
        cout << "NO";
        return;
    }
    vector<bool> vis(200000);
    vector<int> visc(200000);

    auto dfs = [&](auto self, int n, int par)
    {
        if (vis[n])
            return true;
        vis[n] = true;
        visc[n]++;
        bool ans = false;
        for (auto v : g[n])
        {
            if (v != par)
            {
                ans |= self(self, v, n);
                visc[n]++;
            }
        }
        return ans;
    };
    for (int i = 0; i < 20000; i++)
    {
        if (i == iniv && visc[i] > 1 && visc[i] != g[i].size()+1)
        {
            cout << "NO";return;
        }
        if (visc[i] > 1 && visc[i] != g[i].size())
        {
            cout << "NO";
            return;
        }
    }
    for(int i = 0; i < p.size()-1; i++)
    {
        int x = p[i]-1,t = p[i+1]-1;
        auto z = find(all(g[x]),t);
        
        if(z==g[x].end())
        {
            cout << "NO";return;
        }
    }
    if (dfs(dfs, iniv-1, -1))
    {
        cout << "NO";
        return;
    }
    cout << "YES";
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