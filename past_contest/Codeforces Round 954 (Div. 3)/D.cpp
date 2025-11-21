#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    auto calc = [](vector<ll> &v)
    {
        ll ans = 0;
        bool one = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
                return 0LL;
            if (v[i] == 1 )
            {
                one = true;
                continue;
            }
            ans += v[i];
        }
        if(ans == 0 && one)return 1LL;
        return ans;
    };
    vector<ll> aux;
    ll ans = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        aux.clear();
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                aux.push_back((s[j] - '0') * 10 + s[j + 1] - '0');
                j++;
            }
            else
                aux.push_back(s[j] - '0');
        }
        ans = min(ans, calc(aux));
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}