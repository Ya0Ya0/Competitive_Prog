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
    int n; 
    cin >> n;
    read(ent,n);
    vector<ll>pos(n+5);
    for(int i =0;i < n;i++)pos[ent[i]] = i;
    stack<pair<ll,ll>>s;
    vector<pair<ll,ll>>adj;
    for(int i =0;i < n;i++)
    {
        if(s.empty())s.push({ent[i],ent[i]});
        else{
            auto [mn,mx] = s.top();
            s.pop();
            if(ent[i] > mn)
            {
                adj.push_back({mn,ent[i]});
                s.push({mn,max(mx,ent[i])});
            }
            else{
                s.push({mn,mx});
                s.push({ent[i],ent[i]});
            }
        }
        while(s.size() > 1)
        {
            auto [lmn,lmx] = s.top();
            s.pop();
            auto [lmn2,lmx2] = s.top();
            s.pop();
            if(lmx > lmn2)
            {
                adj.push_back({lmx,lmn2});
                s.push({min(lmn,lmn2),max(lmx,lmx2)});
            }else{
                s.push({lmn2,lmx2});
                s.push({lmn,lmx});
                break;
            }
        }
    }
    if(adj.size() != n-1)
    {
        cout <<"No\n";
    }else{
        cout << "Yes\n";
        // for(auto [a,b] : adj)
        // {
        //     cout << a <<" " << b <<"\n";
        // }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}