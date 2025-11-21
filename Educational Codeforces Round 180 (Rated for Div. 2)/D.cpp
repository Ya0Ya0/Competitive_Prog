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
    int n;
    cin >> n;
    // read(ent,n);
    vector<vector<int>> ent(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ent[a].push_back(b);
        ent[b].push_back(a);
    }
    vector<int> dis(n, -1);
    vector<int> parr(n, -1);
    auto dfs = [&](int v, int par, auto self, int deep) -> int
    {
        parr[v] = par;
        dis[v] = deep;
        ll r = v;
        int mx = deep;
        if( ent[v].size() == 2)
        {
            return v;
        }        
        for (auto &e : ent[v])
        {
            if (e != par)
            {
                ll m = self(e, v, self, deep + 1);
                if(m!=-1)return m;
                
            }
        }
        return -1;
    };
    int nn = 0;
    vector<pair<int, int>> ans;

    int f = dfs(0, -1, dfs, 0);
    // int ff = dfs(f, -1, dfs, 0);
    // ll r = parr[parr[ff]];
    // ans.push_back({parr[ff] + 1, ff + 1});
    // ans.push_back({parr[parr[ff]]+1,parr[ff] + 1});
    if(f==-1)
    {
        f = dfs(1, -1, dfs, 0);
        if(f==-1)
        {
            cout << "NO\n";
            return;
        }
        
    }
    auto dfs2 = [&](int v, int par, auto self, int ko, int z) -> int
    {
        for (auto &e : ent[v])
        {
            if (e != par && e!=z)
            {
                if (ko)
                {
                    ans.push_back({v + 1, e + 1});
                }
                else
                {
                    ans.push_back({e + 1, v + 1});
                }
                // if (nn == 0)
                // {
                //     if (ent[e].size() == 2)
                //     {
                //         nn++;
                //         self(e, v, self, ko,z);
                //     }
                // }else
                self(e, v, self, ko ^ 1,z);
                // if(nn==1)ko^=1;
            }
        }
        return 0;
    };
    dfs2(ent[f][0], -1, dfs2, 1, f);
    dfs2(ent[f][1], -1, dfs2, 0, f);
    ans.push_back({ent[f][0] + 1, f+1});
    ans.push_back({f+1,ent[f][1] + 1});
    cout << "YES\n";
    for (auto &e : ans)
    {
        cout << e.first << " " << e.second << "\n";
    }
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