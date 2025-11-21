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
    ll r,c;
    cin >>r >> c;
    vector<vector<ll>>m (r,vector<ll>(c));
    for(int i =0; i < r; i++)
    {
        for(int j =0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }
    for(int i =0; i < r; i++)
    {
        for(int j =0; j < c; j++)
        {
            vector<pair<int,int>>n({{1,0},{0,1},{-1,0},{0,-1}});
            ll ns = INT_MAX;
            ll mx = 0;
            for(int k =0; k < 4; k++)
            {
                auto [a,b] = n[k];
                if(i-a>=0 && i-a <r && j - b>=0 && j-b<c)
                {
                    
                    mx = max(mx,m[i-a][j-b]);
                }
            }
            if(m[i][j]>mx)
                m[i][j] = mx;
        }
    }
    for(int i =0; i < r; i++)
    {
        for(int j =0; j < c; j++)
        {
            cout << m[i][j] <<" ";
        }
        cout << "\n";
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