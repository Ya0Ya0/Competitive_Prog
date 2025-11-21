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
void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int l = 0;
    vector<int>pos(n);
    for (int i = 0; i < n; i++)
    {
        if(g[i].size() == 1){
            l++;
            if(g[g[i][0]].size() == 2)
            {
                pos[i] = 1;
            }
        }
    }
    if(l == n-1)
    {
        cout << l <<"\n";return;
    }
    auto tama = [&](auto self,int p, int n)
    {
        int tam = 1;
        for(auto e : g[n])
        {
            
            if(e != p)
            {                
                tam += self(self,n,p);
            }
        }
        return tam;
    };
    auto leaves = [&](auto self,int p, int n)
    {
        int tam = 0;
        if(g[n].size() == 1)
            return 1;
        for(auto e : g[n])
        {
            
            if(e != p)
            {                
                tam += self(self,n,e);
            }
        }
        return tam;
    };
    for (int i = 0; i < n; i++)
    {
        if(g[i].size() != 1)
        
    }
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