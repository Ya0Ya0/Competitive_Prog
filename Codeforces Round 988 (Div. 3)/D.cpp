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
    ll n,m,L; 
    cin >> n >> m >> L;
    // read(ent,n);
    vector<pair<ll,ll>>h(n),p(m);
    for(int i =0;i <n;i++)
    {
        cin >> h[i].first >> h[i].second;
    }
    for(int i =0;i <m;i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    priority_queue<ll> cur;
    int i=0;
    ll curP=1;
    ll cnt = 0;
    for(ll j =0;j < n;j++)
    {
        while(i <m && p[i].first < h[j].first)
        {
            cur.push(p[i].second);
            i++;
        }
        ll need = h[j].second - h[j].first+1;
        while(cur.size() && curP <= need)
        {
            ll k = cur.top();
            cur.pop();
            curP+=k;
            cnt++;
        }
        if(curP <= need)
        {
            cout << -1 << "\n";return;
        }
    }
    cout << cnt << "\n";
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