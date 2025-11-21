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
    int r,c,n; 
    cin >>r >> c >>n;
    // read(ent,n);
    vector<pair<ll,ll>>ent;
    queue<tuple<ll,ll,ll>>q;
    for(int i =0;i < n;i++)
    {
        ll x,y;
        cin >> x >> y;
        ent.push_back({x-1,y-1});
        q.push({x-1,y-1,i+1});
    }
    //bfs
    
    vector<vector<ll>>vis(r,vector<ll>(c));
    vector<vector<ll>>ans1(r,vector<ll>(c));
    vector<vector<ll>>ans2(r,vector<ll>(c));
    while(!q.empty())
    {
        auto v = q.front();
        q.pop();
        
        if(vis[get<0>(v)][get<1>(v)]>1 || ans1[get<0>(v)][get<1>(v)]==get<2>(v))continue;
        vis[get<0>(v)][get<1>(v)]++;
        if(ans1[get<0>(v)][get<1>(v)]==0)
        {
            ans1[get<0>(v)][get<1>(v)] = get<2>(v);
            
        }else if(ans2[get<0>(v)][get<1>(v)]==0 && ans1[get<0>(v)][get<1>(v)]!=get<2>(v))
        {
            ans2[get<0>(v)][get<1>(v)] = get<2>(v);
        }
        pair<ll,ll>inc{0,1};
        for(int i =0;i < 4;i++)
        {
            if(i == 1)inc = {1,0};
            if(i == 2)inc = {0,-1};
            if(i == 3)inc = {-1,0};
            tuple<ll,ll,ll>nx = {get<0>(v) + inc.first,get<1>(v) + inc.second,get<2>(v)};
            
            if(get<0>(nx) < 0 || get<1>(nx) < 0 || get<0>(nx) >= r || get<1>(nx) >= c)continue;
            if(vis[get<0>(nx)][get<1>(nx)]>1)continue;
            q.push(nx);
        }
    }
    for(int i =0;i < r;i++)
    {
        for(int j =0;j < c;j++)
        {
            cout << ans1[i][j] <<" ";
        }
        cout <<"\n";
    }
    for(int i =0;i < r;i++)
    {
        for(int j =0;j < c;j++)
        {
            cout << ans2[i][j] <<" ";
        }
        cout <<"\n";
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