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
ll mod = 998244353;
const ll mx = 1e6+5;
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a)%mod;
        a = (a * a)%mod;
        b /= 2;
    }
    return r%mod;
}
vector<ll>fact(mx);
void Solve()
{
    ll n;
    // cin >> n;
    // read(ent,n);
    string s;
    cin >> s;
    n = s.length();
    vector<vector<ll>> cnt(n, vector<ll>(26));
    for (ll i = 0; i < n; i++)
    {
        if(i > 0)
        for (ll j = 0; j < 26; j++)
        {
            
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][s[i] - 'a']++;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll r, l;
        string qq;
        cin >> qq;
        if (qq == "INSIDE")
        {
            string t;
            cin >> l >> r >> t;
            vector<ll> f(26);
            for (auto e : t)
            {
                f[e - 'a']++;
            }
            bool ok = 1;
            for (ll i = 0; i < 26; i++)
            {
                ll zz = cnt[r - 1][i] - (l > 1 ? cnt[l - 2][i] : 0);
                if (f[i] != zz)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
        else
        {
            ll ans =0;
            cin >> l >> r;
            ans = fact[r-l+1];
            for(ll i=0;i<26;i++)
            {
                ll val = cnt[r-1][i] - (l > 1 ? cnt[l - 2][i] : 0);
                ans = (ans * elevar(fact[val],mod-2))%mod;
            }
            cout << ans << "\n";
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    fact[0] = 1;
    
    for(ll i=1;i<mx;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    while (tt--)
    {
        Solve();
    }
}