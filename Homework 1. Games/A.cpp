#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
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
vector<vector<int>>g(105,vector<int>(105,0));
void init()
{
    int n = 105;
    
    g[0][0] = 0;
    for(int i =0;i < n;i++)
    {
        for(int j =0;j <n;j++)
        {
            // row[i].insert(g[i][j]);
            // col[j].insert(g[i][j]);
            // if(j ==0 && i == 0 )continue;
            int state = 0;
            set<int>mx;
            for(int k =0;k < i;k++)
            {
                mx.insert(g[k][j]);
            }
            for(int k =0;k < j;k++)
            {
                mx.insert(g[i][k]);
            }
            for(int k =1;k <= i && k <= j;k++)
            {
                mx.insert(g[i-k][j-k]);
            }
            while(mx.count(state))state++;
            g[i][j] = state;            
        }
    }
    g[0][0]=1;
}
void Solve()
{
    int n; 
    cin >> n;
    // read(ent,n);
    init();
    int ans = 0;
    int k =0;
    int x = 20;
    // for(int i =0;i <x;i++)
    // {
    //     for(int j =0;j <x;j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i =0;i < n;i++)
    {
        int a,b;cin >> a >> b;
         if(a ==0 || b == 0 || a == b) k = 1;
        ans = ans^(g[a][b]);
    }
    if(ans != 0 || k)
    {
        cout << "Y\n";
    }else {
        cout << "N\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}