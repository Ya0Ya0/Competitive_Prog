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
    int n;
    cin >> n;
    int red, blue;
    cin >> red >> blue;
    vector<vector<int>> g(n + 1);
    vector<int> p(n + 1);
    vector<int> dep(n + 1);
    dep[0] = -1;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int far = 0;
    auto dfs = [&](auto&& self, int cur, int par)->void
    {
        p[cur] = par;
        dep[cur] = dep[par] + 1;
        far = max(far, dep[cur]);
        for (auto s : g[cur])
        {
            if (s !=par)
                self(self, s, cur);
        }
        
    };
    auto path = [&](int a, int b)
    {
        vector<int> pre, suf;
        if (dep[a] > dep[b])
        {
            swap(a, b);
        }
        pre.push_back(b);        
        while (dep[b] != dep[a])
        {
            b = p[b];
            pre.push_back(b);
        }
        if(a == b)return pre;
        suf.push_back(a);
        while (p[a] != p[b])
        {
            a = p[a];
            b = p[b];
            pre.push_back(b);
            suf.push_back(a);
        }
        pre.push_back(p[a]);
        reverse(all(suf));
        for (auto i : suf)
            pre.push_back(i);
        return pre;
    };
    if(red == blue)
    {
        dfs(dfs,red,0);
        cout <<  (n-1)*2 - far << '\n';return;
    }
    dfs(dfs,1,0);
    vector<int> pat = path(red,blue);
    if(pat[0]!=red)reverse(all(pat));
    int mid = (pat.size()+1)/2 - 1;
    far = 0;
    dfs(dfs,pat[mid],0);
    cout << (2*(n-1) - far) + pat.size()-mid-1 << "\n";
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
