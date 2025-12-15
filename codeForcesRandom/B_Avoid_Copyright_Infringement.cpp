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
    ll a, b, c;
    cin >> a >> b >> c;
    string ans = "";

    set<pair<ll, char>, greater<pair<ll, char>>> q;
    if (a)
        q.insert({a, 'M'});
    if (b)
        q.insert({b, 'I'});
    if (c)
        q.insert({c, 'T'});
    auto f = [&]() -> void
    {
        while (q.size())
        {
            // pair<ll,char> cur = q.top();
            // q.pop();
            vector<pair<ll, char>> out;
            while (q.size())
            {
                pair<ll, char> cur = *q.begin();
                q.erase(cur);
                bool ss = (ans.size() >= 2) && (min(ans[ans.size() - 2], cur.second) == 'M' && max(ans[ans.size() - 2], cur.second) == 'T');
                if (ans.size() == 0 || ((ans.back() != cur.second) && !ss))
                {
                    ans.push_back(cur.second);
                    cur.first--;
                    if (cur.first)
                        q.insert(cur);
                    break;
                }
                else
                {
                    out.push_back(cur);
                }
                if (q.empty())
                {
                    // cout << "No\n";
                    return;
                }
            }
            for (auto z : out)
                q.insert(z);
        }
        return;
    };
    bool ok = false;
    for (int i = 0; i < 3; i++)
    {
        q.clear();
        ans.clear();
        if (i == 0 && a)
        {
            ans = "M";
            if (a - 1)
                q.insert({a - 1, 'M'});
        }
        else if (a)
        {
            q.insert({a, 'M'});
        }
        if (i == 1 && b)
        {
            ans = "I";
            if(b-1)
            q.insert({b - 1, 'I'});
        }
        else if (b)
        {
            q.insert({b, 'I'});
        }
        if (i == 2 && c)
        {
            ans = "T";
            if(c-1)
            q.insert({c - 1, 'T'});
        }
        else if (c)
        {
            q.insert({c, 'T'});
        }
        f();
        if (ans.size() == a + b + c)
        {
            ok = 1;
            break;
        }
    }
    if (!ok)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    cout << ans << "\n";
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