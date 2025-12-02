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
void init(){};
void Solve()
{
    int n; 
    cin >> n;
    // read(ent,n);
    vector<vector<int>>t(n);
    for(int i =0;i <n-1;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    vector<int>lst;
    vector<int>dis(n,-n);
    queue<int>q;
    dis[0] = 0;
    q.push(0);
    vector<int>even,odd;
    vector<pair<int,int>>ope;
    int pos = 0;
    auto dfs = [&](auto self,int nd,int par)->bool{
        bool ok = false;
        // if(dis[nd]&1) odd.push_back(nd);
        // else even.push_back(nd);
        for(auto e : t[nd]){
            if(e== par)continue;
            dis[e] = dis[nd]+1;
            ok |= self(self,e,nd);
        }
        if(ok || nd == n-1){
            lst.push_back(nd);
            return true;
        }
        // if(ope.empty() && ! ){
        //     ope.push_back({1,-1});
        // }
        int z = (dis[nd] & 1);
        if(z == pos){
            ope.push_back({1,-1});
        }
        ope.push_back({2,nd});
        ope.push_back({1,-1});
        pos ^= 1;
        return ok;
    };
    dfs(dfs,0,-1);
    ll par = (ope.size()+1) /2;
    if(!(par & 1)){
        ope.push_back({1,-1});
    }
    reverse(all(lst));
    for(int i =0;i < lst.size()-1;i++){
        ope.push_back({2,lst[i]});
        ope.push_back({1,-1});
    }
    cout << ope.size() <<"\n";
    for(auto [a,b] : ope){
        if(a == 1){
            cout << a <<"\n";
        }else{
            cout << a  << " " << b+1<<"\n";
        }
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
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