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
    ll n, k;
    cin >> n >> k;
    // read(ent,n);
    string z;
    ll j = n;
    while (j)
    {
        if (j & 1)
            z += "1";
        else
            z += "0";
        j /= 2;
    }
    ll ans = 0;
    if (k > 2 * z.size())
    {
        ans += k - z.size();
        k = z.size();
    }
    // reverse(all(z));
    ll dp[33][70] = {};
    // ll best[40] = {};
    for (int i = 0; i < z.size(); i++)
    {
        string jj = z;
        int car = 0;
        int skp = 0;
        int usk = 0;
        ll cnt = 0;
        // cnt = usk,skp;
        // int z = __builtin_popcount(usk);
        for (int j = i; j < z.size() && (usk < k || car); j++)
        {
            if (j == 3)
            {
                int k = 1 + 1;
                int z = k + 2;
            }
            if (car)
            {
                if (jj[j] == '0' && usk < k)
                {
                    usk++;
                    car = 1;
                }
                else if (jj[j] == '0')
                {
                    if (usk < k - 1)
                    {
                        car = 1;
                    }
                    else
                        car = 0;
                }
            }
            else if (jj[j] == '1')
            {
                car = 1;
                usk++;
            }
            else if (usk < k - 1)
            {
                usk += 2;
                car = 1;
            }
            else
            {
                car = 0;
            }
            cnt += car;

            dp[j][usk] = max(dp[j][usk], cnt);
            for (int o = 1; o + usk <= k; o++)
            {
                for (int ii = 0; ii < i; ii++)
                {
                    dp[j][o + usk] = max(dp[j][o + usk], dp[ii][o] + cnt);
                }
            }
        }
    }
    ll fans = 0;
    for (int i = 0; i < z.size(); i++)
    {
        for (int j = 1; j <= k; j++)
        {
            fans = max(fans, ans + dp[i][j] + k - j);
        }
    }
    cout << fans << "\n";
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