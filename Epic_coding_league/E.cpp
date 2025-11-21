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
    // read(ent,n);
    vector<string> v(n);
    for (auto &s : v)
        cin >> s;
    map<int, ll> v1, v2, h1, h2, d1, d2;
    ll mx = 0,mx2=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (v[i][j] == 'X')
            {
                if(i>0 && j>0 && v[i-1][j-1] == 'X')
                d1[i + j]++;
                if(i>0  && v[i-1][j] == 'X')
                v1[j]++;
                if(j>0  && v[i][j-1] == 'X')
                h1[i]++;
                
                mx = max(mx,d1[i + j]);
                mx = max(mx,h1[i]);
                mx = max(mx,v1[i]);
            }
            else if(v[i][j] == 'O')
            {
                if(i>0 && j>0 && v[i-1][j-1] == 'O')
                d2[i + j]++;
                if(i>0  && v[i-1][j] == 'O')
                v2[j]++;
                if(j>0  && v[i][j-1] == 'O')
                h2[i]++;
                
                mx2 = max(mx2,d2[i + j]);
                mx2 = max(mx2,h2[i]);
                mx2 = max(mx2,v2[i]);
            }
        }
    }
    cout << mx <<" " << mx2 ;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}