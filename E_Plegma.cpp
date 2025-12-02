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
void Solve2(){
    int n;cin >> n;
    string r,c;
    cin >> r >> c;
    if(r[0] == '0' || c[n-1] == '0'){
        cout << 0 <<"\n";
    }else{
        cout << 1 <<"\n";
    }
}
void Solve()
{
    int n,C; 
    cin >> n >> C;
    // read(ent,n);
    vector<string>v(n);
    for(auto &s : v)cin >> s;
    int r=1,c = 1;
    if(C == 0){
        for(int i =0;i < n;i++)
        {
            if(v[i][0] != '1'){
                r = i+1;
                break;
            }
        }
        for(int i =0;i < n;i++)
        {
            if(v[n-1][i] != '1'){
                r = i+1;
                break;
            }
        }
        cout << r << " " << c <<"\n";
    }
    else{
        cout << 1 << " " << n <<"\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    string s;cin >> s;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        if(s == "first")Solve();
        else Solve2();
    }
}