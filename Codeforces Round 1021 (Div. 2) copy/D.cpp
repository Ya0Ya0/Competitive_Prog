// #include "bits/stdc++.h"
// using namespace std;
// #define ll long long
// #define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
// #define all(x) x.begin(), x.end()

// #define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
// struct custom_hash
// {
//     static uint64_t splitmix64(uint64_t x)
//     {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// long long elevar(long long a, long long b)
// {
//     long long r = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             r = r * a;
//         a = a * a;
//         b /= 2;
//     }
//     return r;
// }
// ll mod = 1e9 +7;
// void Solve()
// {
//     ll n,m,k; 
//     cin >> n >> m >> k;
//     // ll ans =1;
//     vector<pair<int,int>>p;
//     for(int i =0;i <=k;i++)
//     {
//         int a,b;cin >> a >> b;
//         p.push_back({a,b});
//     }
//     vector<vector<ll>>ans(n,vector<ll>(m));
//     vector<vector<ll>>seen(n,vector<ll>(m,-1));
//     // vector<vector<ll>>cnt(n,vector<ll>(m,-1));
//     ans[p[0].first][p[0].second]=1;
//     for(int i =1;i<=k;i++)
//     {
//         int dx = p[i].first-p[i-1].first;
//         int dy = p[i].second-p[i-1].second;
//         dx = abs(dx);
//         dy = abs(dy);
//         int see = 0;
//         if(dx==1 && dy==1 ){
//             ll curx = p[i].first - dx;
//             ll cury = p[i].second;
//             ll curxx = p[i].first;
//             ll curyy = p[i].second - dy;
//             if(seen[curx][cury]!=-1)
//             {
//                 see++;
//                 // cnt[curx][cury]++;
//                 ll val = ans[p[seen[curx][cury]].first][p[seen[curx][cury]].second];
//                 ans[p[i].first][p[i].second]+= val;
//             }else{
//                 ans[p[i].first][p[i].second]+= ans[p[i-1].first][p[i-1].second];
//             }
//             curx = p[i].first;
//             cury = p[i].second - dy;
//             if(seen[curx][cury]!=-1)
//             {
//                 // cnt[curx][cury]++;
//                 ll val = ans[p[seen[curx][cury]].first][p[seen[curx][cury]].second];
//                 ans[p[i].first][p[i].second]+= val;
//             }else{
//                 ans[p[i].first][p[i].second]+= ans[p[i-1].first][p[i-1].second];
//             }
//         }
//         else if(dx == 2 && dy == 0)continue;
//         else if(dy == 2 && dx == 0)continue;
//         else ans = 0;
        
//     }
//     cout << ans <<"\n";
    
// }

// int main()
// {
//     //freopen("input.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tt = 1;
//     cin >> tt;
//     while (tt--)
//     {
//         Solve();
//     }
// }