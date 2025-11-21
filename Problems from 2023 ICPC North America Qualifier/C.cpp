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
    ll n, k; 
    cin >> n >> k;
    // read(ent,n);
    vector<pair<ll,ll>>food(n);
    for(auto &[a,b] : food)cin >> a >> b;
    double ans = 0;
    vector<ll>fp(n+5),bad(n+5);
    vector<double>pre(n+5);
    fp[0] = food[0].first;
    bad[food[0].second]=food[0].first;
    pre[0] =  food[0].first;
    pre[food[0].second]-=food[0].first;
    if(pre[0] <= 0)
    {
        cout << -1 <<"\n";return;
    }
    for(int i =1;i <n;i++)
    {
        
        // fp[i] = fp[i-1];
        pre[i] = pre[i-1];
        pre[i] +=food[i].first;
        pre[food[i].second]-=food[0].first;

        fp[i]+=food[i].first;
        bad[food[i].second]=food[i].first;
        if(pre[i]<=0)
        {
            cout << -1 <<"\n";return;
        }
    }
    double l = 0, r = food[0].first;
    double eps = 1e-10;
    auto ck = [&](double mid)->bool
    {
        double ini = fp[0];
        ini-=mid*k;
        if(ini<=0)return false;
        ll sum = fp[0];
        double cur = ini;
        for(int i = 1;i < n;i++)
        {   
            cur+=fp[i];
            sum+=fp[i];
            
            cur = min(cur,(double)sum - bad[i]);
            cur-=mid*k;
            sum-=bad[i];
            if(cur <= 0)return false;
        }
        return true;
    };
    int c =0;
    while(r-l > eps)
    {
        if(c > 65)break;
        double mid = (l+r)/2;
        if(ck(mid))l = mid;
        else r = mid;
        c++;
    }
    if(l == 0)l = -1;
    cout << fixed << setprecision(10)<< l <<"\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}