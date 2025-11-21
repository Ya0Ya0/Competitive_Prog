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
    int n;cin >> n;
    vector<ll>ent(n);
    for(auto &e : ent)cin >> e;
    stack<pair<ll,ll>>stk;
    stk.push({ent[n-1],1});
    for(int i =n-2;i>=0;i--)
    {
        ll val = stk.top().first / stk.top().second;
        if(ent[i] >= val)
        {
            auto cur = stk.top();
            stk.pop();
            cur.first+=ent[i];
            cur.second++;                        
            while(stk.size() )
            {
                val = cur.first / cur.second;
                ll nxt = stk.top().first / stk.top().second;
                if(val < nxt)break;
                else{
                    cur.first+=stk.top().first;
                    cur.second+=stk.top().second;
                    stk.pop();
                }
            }
            stk.push(cur);
        }
        else{
            stk.push({ent[i],1});
        }
    }
    ll mini = stk.top().first / stk.top().second;
    ll mx = 0;
    while(stk.size())
    {
        auto cur = (stk.top().first+stk.top().second-1) / stk.top().second;
        mx = max(cur,mx);
        stk.pop();
    }
    cout << mx - mini << "\n";
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