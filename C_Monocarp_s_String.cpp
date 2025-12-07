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
    string s;
    cin >> s;
    vector<int> v(n);
    ll cur = 0;
    ll ans = n;
    ll need = 0;
    for (auto c : s)
        need += c == 'a' ? 1 : -1;

    if (need == 0)
    {
        cout << 0 << "\n";
        return;
    }
    if (need < 0)
    {
        for (auto &c : s)
            c = c == 'a' ? 'b' : 'a';
    }
    need = abs(need);
    for (ll i = 0, j = 0; i < n; i++)
    {

        cur += s[i] == 'a' ? 1 : -1;
        while (cur < 0)
        {
            cur -= s[j] == 'a' ? 1 : -1;
            j++;
        }
        while (cur >= need)
        {
            ans = min(ans, i - j + 1);
            cur -= s[j] == 'a' ? 1 : -1;
            j++;
            while (cur < 0)
            {
                cur -= s[j] == 'a' ? 1 : -1;
                j++;
            }
        }
        if (i == n - 1)
        {
            while (j <= i)
            {
                if (cur >= need)
                    ans = min(ans, i - j + 1);
                cur -= s[j] == 'a' ? 1 : -1;
                j++;
            }
        }
    }
    cout << (ans == n ? -1 : ans) << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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