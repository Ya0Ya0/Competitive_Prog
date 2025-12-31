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
long long elevar(long long a, long long b, ll c = LONG_LONG_MAX-5)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a)%c;
        a = (a * a)%c;
        b /= 2;
    }
    return r;
}
int func(int n)
{
    if(n <= 0)return 0;
    if(n == 1)return 2;
    else return func(n-1)+func(n-2);
}
void Solve()
{// 
    cout << func(6);
    // ll n,k;
    // cin >> n >>k;
    // string s,t;cin >> s >> t;
    // vector<string>ss;
    // for(int i =0;i < k;i++)
    // {
    //     if(s == t)break;
    //     vector<bool>ch(n);
    //     for(int j = n-1,k = n-1;k>=0 && j>=0;j--)
    //     {
    //         k = min(j,k);
    //         if(s[k] == t[j])continue;
    //         else{
    //             while(j >= 0 && t[j] != s[k])k--;
    //             if(k>=0){
    //                 ch[k]=true;
    //             }
    //         }
    //     }
    //     for(int i =n-1;i >=0;i--)
    //     {
    //         if(ch[i])s[i+1] = s[i];
    //     }
    //     ss.push_back(s);
    // }
    // if(s == t)
    // {
    //     cout << ss.size() <<'\n';
    //     for(auto str : ss)cout << str <<"\n";
    // }else{
    //     cout << -1 <<"\n";
    // }
    
    // read(ent, n);
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
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}