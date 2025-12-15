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
void init() {};
void Solve()
{
    int n;
    cin >> n;
    // read(ent,n);
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<pair<ll, pair<ll, ll>>> s;
    s.push_back({v[0][0], {0, 0}});
    vector<vector<pair<ll, ll>>> par(n, vector<pair<ll, ll>>(n));
    vector<vector<bool>>seen(n,vector<bool>(n));
    par[0][0] = {-1,-1};
    ll mn = LONG_LONG_MAX/10;
    while (!s.empty())
    {
        vector<pair<ll, pair<ll, ll>>> k;
        ll nmn = LONG_LONG_MAX/10;        
        for (auto [a, b] : s)
        {
            if (a > mn)
                continue;
            if (b.first + 1 < n && !seen[b.first + 1][b.second])
            {   
                par[b.first + 1][b.second] = b;
                k.push_back({v[b.first + 1][b.second], {b.first + 1, b.second}});
                nmn = min((ll)v[b.first + 1][b.second],nmn);
                seen[b.first + 1][b.second] = 1;
            }
            if (b.second + 1 < n && !seen[b.first ][b.second+1])
            {
                par[b.first ][b.second+1] = b;
                k.push_back({v[b.first ][b.second+1], {b.first , b.second+1}});
                nmn = min((ll)v[b.first ][b.second+1],nmn);
                seen[b.first ][b.second+1] = 1;
            }
        }
        s = k;
        mn = nmn;
    }
    auto z = make_pair(n-1LL,n-1LL);
    string ans;
    while(z != make_pair(-1LL,-1LL)){
        ans.push_back(v[z.first][z.second]);
        z = par[z.first][z.second];
    }
    reverse(all(ans));
    cout << ans <<"\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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