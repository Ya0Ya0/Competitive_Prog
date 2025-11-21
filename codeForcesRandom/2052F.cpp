#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
#define read(name, n)    \
    vector<ll> name(n);  \
    for (auto &e : name) \
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
ll c = 5001;
ll mod = 1e9 + 7;
void Solve()
{
    ll n;
    cin >> n;
    vector<string> enst(2);
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (auto &e : enst)
        cin >> e;
    // vector<vector<char>> ent(n + 1, vector<char>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (enst[j][i] != '.')
            {
                dp[i][j] = 1;
            }
        }
    }
    // ll ans = 0;
    vector<int> up(n + 1), dw(n + 1);
    // int lu=-1,ld=-1,ans =0;
    // for(int i =0;i <n;i++)
    // {
    //     if(ent[0][i] == '.')
    //     {
    //         if(lu==-1)lu = i;

    //     }else{
    //         if()
    //     }
    //     if(ent[1][i] == '.')
    //     {
    //         if(ld==-1)ld = i;
    //     }else{

    //     }
    // }
    // ll ans =1;
    vector<vector<bool>> mul(n + 1, vector<bool>(2));
    // bool mul[n+1][2]={};
    // dp[0][0] = dp[0][1] = 1;
    ll ans =1;
    for (int i = 0; i < n; i++)
    {
        
            if(dp[i][0]==0 && i < n-1 && dp[i+1][0] == 0 && dp[i][1]==0 && i < n-1 && dp[i+1][1] == 0)
            {
                ans = ans==0?0:2;
            }
            if (dp[i][0] == dp[i][1] && dp[i][1] == 0)
            {
                dp[i][0] = dp[i][1] = 1;
            }
            if(dp[i][0]==0 && i < n-1)
            {
                if(dp[i+1][0] == 0)
                {
                    dp[i][0]=dp[i+1][0]=1;
                }else{
                    ans =0;
                }
            }
            if(dp[i][1]==0 && i < n-1)
            {
                if(dp[i+1][1] == 0)
                {
                    dp[i][1]=dp[i+1][1]=1;
                }else{
                    ans =0;
                }
            }
            if (dp[i][0] != dp[i][1])
            {
                ans =0;
            }
        
    }
    
    if (ans==2)
    {
        cout << "Multiple\n";
    }
    else if (ans)
    {
        cout << "Unique\n";
    }
    else
    {
        cout << "None\n";
    }
}
void init()
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}