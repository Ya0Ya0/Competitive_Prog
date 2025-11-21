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
    vector<pair<ll, int>> gaps;
    ll ini = 0;
    for (int i = 0; i < n; i++)
    {
        ll sz = 0;
        int plus = 0;
        int ex = i == 0 || i == n - 1;
        if (s[i] == '1' && i < n - 1 && s[i + 1] == '1')
            ini++;
        while (i < n && s[i] == '0')
        {
            i++;
            sz++;
            plus = -1;
        }
        ex = (i == n ) ? 1 : ex;
        if (sz > 0)
            gaps.push_back({sz, ex});
        i += plus;
    }
    sort(all(gaps));

    vector<ll> ans{ini};
    ll cur = ini;
    for (int i = 1, j = 0; j < gaps.size(); i++)
    {
        if (i < gaps[j].first)
        {
            ans.push_back(++cur);
        }
        else if (i == gaps[j].first)
        {
            cur += 1 + (gaps[j].second == 0);
            ans.push_back(cur);
            i = 0;
            j++;
        }
    }
    ll minus = 0;
    if (ans.size() == n + 1)
    {
        minus = 1;
    }
    cur = n - 1;
    ll start = 0;
    ll cnt = 0;
    while (start < n && s[start] == '1')
        start++, cnt++;
    ll end = n - 1;
    while (end >= 0 && s[end] == '1')
        end--, cnt++;
    if (start > end)
    {
        swap(start, end);
        start = 0;
        cnt/=2;
    }
    for (int i = 0; i < cnt; i++)
    {
        ans.push_back(--cur);
    }
    for (int i = start + 1; i < end; i++)
    {
        if (s[i] == '1')
        {
            cur -= 2;
            ans.push_back(cur);
            while (s[++i] == 1)
            {
                ans.push_back(--cur);
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        cout << ans[i] - minus << " ";
    }
    cout << "\n";
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