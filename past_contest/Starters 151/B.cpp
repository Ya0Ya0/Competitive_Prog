#include"bits/stdc++.h"
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
    stack<pair<ll,ll>>stk;
    int n;cin >> n;
    vector<pair<ll,ll>>pos(n);
    
    for(auto &e : pos)cin >> e.first;
    for(auto &e : pos)cin >> e.second;
    // sort(all(pos),[](pair<ll,ll>a,pair<ll,ll>b){
    //     if(a.first == b.first)
    //     {
    //         return a.second > b.second;
    //     }
    //     else return a.first < b.second;
    // });
    sort(all(pos));
    auto cmp = [](pair<ll,ll>a,pair<ll,ll>b)
    {
        ll aa = a.first*b.second,bb = b.first*a.second;
        if(aa > bb)return 1;
        if(aa < bb)return -1;
        else return 0;
    };
    for(int i =0; i < n;i++)
    {
        auto cur = pos[i];
        while(!stk.empty())
        {
            auto mn = stk.top();
            if(cmp(mn,cur) == 1)
            {
                stk.pop();
            }
            else break;
        }
        stk.push(cur);
    }
    cout << stk.size() << "\n";
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