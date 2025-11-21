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
    int n, m;
    cin >> m >> n;
    vector<string> og(m);
    vector<ll> ogH(m);
    for(int i =0;i <m;i++)
    {
        cin >> og[i];
    }
    std::srand(std::time(0));
    ll p =  687678678678;
    ll mod =6786876784411;
    vector<ll> hs(505);
    for (ll h = 1, i = 0; i < 505; i++)
    {
        h = (h * p + mod) % mod;
        hs[i] = h;
    }
    vector<vector<ll>> hash(n, vector<ll>(m));
    vector<ll> ok(m),cnt(n);
    for(int i =0;i <m;i++)
    for (int z = 0; z < og[i].size(); z++)
    {
        ogH[i]= (ogH[i] + hs[z] * (og[i][z] - 'a' + 1) + mod) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            for (int z = 0; z < s.size(); z++)
            {
                hash[i][j] = (hash[i][j] + hs[z] * (s[z] - 'a' + 1) + mod) % mod;
            }
            if(hash[i][j]==ogH[j])
            {
                ok[j] = true;
                cnt[i]++;
            }
        }
    }
    ll ans =0;
    ll res = 1;
    for(int i =0;i <m;i++)
    {
        if(!ok[i])res = 0;
    }
    if(!res)
    {
        cout << -1 <<"\n";return;
    }
    ll ex = 0;
    for(int i =0;i <n;i++)
    {
       ex = max(ex,cnt[i]);
    }
    ans+= m + (m - ex)*2;
    cout << ans <<"\n";
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