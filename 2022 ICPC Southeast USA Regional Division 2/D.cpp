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
void Solve()
{
    int r,c; 
    cin >> r >>c;
    // read(ent,n);
    vector<string>v(r);
    queue<tuple<int,int,int>>q;
    for(auto &s : v)cin >> s;
    vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    for(int i =0;i <r;i++)
    {
        for(int j =0;j < c;j++)
        {
            if(i == 0 || j ==0 || i == r-1 || j == c-1)
            {
                q.push({i,j,1});
            }
            for(auto [a,b] : dir)
            {
                if(i+a >= 0 && j+b>=0 && i+a < r && j+b < c && v[i+a][j+b]=='-')
                {
                    q.push({i,j,1});
                    break;
                }
            }
        }
    }
    int ans =0;
    vector<vector<bool>>vis(r,vector<bool>(c));
    while(!q.empty())
    {
        auto [x,y,d] = q.front();
        q.pop();
        if(vis[x][y])continue;
        vis[x][y]=true;
        int curDis = d;
        ans = max(curDis,ans);
        for(auto [a,b] : dir)
        {
            if(x+a >= 0 && y+b>=0 && x+a < r && y+b < c &&v[x+a][y+b]=='X' && !vis[x+a][y+b])
            {
                q.push({x+a,y+b,d+1});
            }
            
        }
    }
    cout << ans <<"\n";

}
/*
5 5
-X-XX
XXXXX
XXXXX
-XXX-
--X--


*/
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