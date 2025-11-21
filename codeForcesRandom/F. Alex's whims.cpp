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

void Solve()
{
    ll n,q;
    cin >> n >> q;
    vector<vector<ll>>adj(n);
    adj[0].push_back(1);
    adj[1].push_back(0);
    ll prev = 1;
    cout << 0+1 << " " << 1+1 <<"\n";
    for(int i = 2;i < n;i++)
    {
        cout << i << " " << i+1 <<"\n";
        adj[i-1].push_back(i);
        adj[i].push_back(i-1);
    }
    vector<int>l,r;
    for(int i =2;i < n;i++)l.push_back(i);
    vector<int>qqq(q);for(auto &e : qqq)cin >> e;
    for(int i =0;i <q;i++)
    {
        int d = qqq[i];
        d--;
        if(l.size() > d)
        {
            ll rr = r.size()?r.back() : 1;
            cout << l[d]+1 <<" " << l[d-1]+1 <<" " << rr+1 <<"\n";
            for(int j = d;j < l.size();j++)
            {
                r.push_back(l[j]);
            }
            ll z = l.size();
            for(int j = d;j < z;j++)
            {
                l.pop_back();
            }
        }
        else if(l.size() < d){
            ll need = d - l.size();
            ll rr = r.size() - need > 0?r[r.size()-need-1] : 1;
            ll lf = l.size()?l.back() : 1;
            cout << r[r.size()-need]+1 <<" " << rr+1 <<" " << lf+1 <<"\n";
            for(int j = r.size()-need;j < r.size();j++)
            {
                l.push_back(r[j]);
            }
            ll z = r.size();
            for(int j = r.size()-need;j < z;j++)
            {
                r.pop_back();
            }
        }
        else{
            cout << -1 <<" "<< -1 <<" "<< -1 <<"\n";
        }
    }
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
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}