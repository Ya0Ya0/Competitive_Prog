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
    read(ent,n);
    int l = 0,mid = 0,r =0;
    vector<ll>pre(n);pre[0] = ent[0];
    for(int i =1;i <n;i++){
        pre[i ]= pre[i-1] + ent[i];
    }
    for(int i =0;i < n-2;i++){
        l = pre[i];
        for(int j =i+1;j < n-1;j++){
            mid = pre[j] - pre[i];
            r = pre[n-1] - pre[j];
            set<ll>s{l%3,mid%3,r%3};
            if(s.size() == 3 || s.size() == 1){
                cout << i+1 <<" " << j+1 <<"\n";
                return;
            }
        }
    }
    cout << 0 <<" " << 0 <<"\n";
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