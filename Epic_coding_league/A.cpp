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
    ll cnt = 0;
    vector<string> v(n);
    vector<vector<int>> k(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v[i] = s;
        for (auto c : s)
        {
            if (c == '#')
                cnt++;
        }
    }
    char pr = v[0][0];
    int ans = 0;
    int cur = 0;
    k[0][0] = true;
    for (int i = 1; i < n; i++)
    {
        int ok = true;
        char lst = v[i][0];
        for (int j = 0, k = i; j < n && k >= 0; j++, k--)
        {
            if (v[k][j] != lst)
                ok = false;
            lst = v[k][j];
        }
        if (ok)
            k[i][0] = true;
        if (ok && lst != v[i - 1][0] && k[i - 1][0])
            cur++;
        else
        {
            if (cur > 0)
                ans += cur + 1;

            cur = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int ok = true;
        char lst = v[n - 1][i];
        for (int j = i, k = n - 1; j < n && k >= 0; j++, k--)
        {
            if (v[k][j] != lst)
                ok = false;
            lst = v[k][j];
        }
        if (ok)
            k[n-1][i] = true;
        if (ok && lst != v[n - 1][i - 1] && k[n - 1][i - 1])
            cur++;
        else
        {
            if (cur > 0)
                ans += cur + 1;

            cur = 0;
        }
    }
    if (cur > 0)
        ans += cur + 1;
    cout << ans << "\n";
    // cout <<"# " << cnt <<"\n" << ". " << n*n-cnt <<"\n";
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