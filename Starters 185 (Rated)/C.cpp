#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
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
    n*=2;
    read(ent, n);
    deque<ll> dq;
    priority_queue<ll, vector<ll>, less<ll>> q;
    map<ll, ll> mp;
    for (auto e : ent)
    {
        dq.push_back(e);
        q.push(e);
        mp[e]++;
    }
    ll sum = 0;
    int t = 1;
    while (!dq.empty() && !q.empty())
    {
        if (t)
        {
            ll z = q.top();
            q.pop();
            
            while(!mp[z] && !q.empty())
            {
                z = q.top();
                q.pop();
                 
            }
            if(mp[z]==0)break;
            mp[z]--;
            sum+=z;
        }else{
            ll z = dq.front();dq.pop_front();
            while(!mp[z] && !dq.empty())
            {
                z = dq.front();dq.pop_front();
            }
            mp[z]--;
        }
        t^=1;
    }
    cout << sum <<"\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}