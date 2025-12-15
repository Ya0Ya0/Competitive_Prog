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
ll const mod = 998244353;

long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a + mod) % mod;
        a = (a * a + mod) % mod;
        b /= 2;
    }
    return r;
}
// ll const mod = 998244353;
void Solve()
{
    int n;
    cin >> n;
    read(ent, n);
    vector<ll> cnt(10);
    for (int i = 0; i < n; i++)
    {
        cnt[ent[i]]++;
    }
    auto ask = [&](int o) -> vector<ll>
    {
        if (o)
        {
            cout << "- 0" << endl;
        }
        vector<ll> ans(n);
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> ans[i];
        }
        return ans;
    };
    vector<ll> r;
    ll cur = -1;
    vector<ll> aux(10);
    bool ok = true;
    while (ok)
    {
        r = ask(1);
        for (int i = 1; i < 10; i++)
        {
            aux[i] = 0;
        }
        for (auto &e : r)
            aux[e]++;
        for (int i = 1; i < 10; i++)
        {
            if (aux[i] > cnt[i])
            {
                cur = i;
                ok = false;
                break;
            }
        }
    }
    cout << "- " << n - aux[cur];
    
    for (int i = 0; i < n; i++)
    {
        if (r[i] != cur)
        {
            cout << " " << i + 1;
            aux[r[i]] = 0;
        }
    }
    cout << endl;
    n = aux[cur];
    r = ask(0);
    
    cnt = aux;
    ok = 1;
    while (ok)
    {        
        for (int i = 1; i < 10; i++)
        {
            aux[i] = 0;
        }
        for (auto &e : r)
            aux[e]++;
        for (int i = 1; i < 10; i++)
        {
            if (aux[i] > cnt[i])
            {
                cur = i;
                ok = false;
                break;
            }
        }
        if(!ok)
            break;
        r = ask(1);
    }
    for(int i = 0; i < n; i++)
    {
        if (r[i] == cur)
        {
            cout << "! " << i+1 << endl;return;
        }
    }
    cout << -1 << endl;
    // assert(false);
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