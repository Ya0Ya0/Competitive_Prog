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
    // int n;
    // cin >> n;
    // read(ent,n);
    pair<ll, ll> bt = {144, 84};
    ll pr = 0, py = 0;
    auto dif = [&](ll a, ll b) -> ll
    {
        ll z = abs(a - bt.first) * abs(a - bt.first) + abs(b - bt.second) * abs(b - bt.second);
        //  z = sqrt(z);
        return z;
    };
    const double EPS = 1e-9;
    for (int i = 0; i < 10; i++)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> r, y;
        vector<ll> dis1, dis2;
        for (int j = 0; j < n; j++)
        {
            ll x1, x2;
            cin >> x1 >> x2;
            r.push_back({x1, x2});
            dis1.push_back(dif(x1, x2));
        }
        cin >> n;
        sort(all(dis1));
        for (int j = 0; j < n; j++)
        {
            ll x1, x2;
            cin >> x1 >> x2;
            r.push_back({x1, x2});
            dis2.push_back(dif(x1, x2));
        }
        sort(all(dis2));
        if (dis1.size() == 0)
        {
            py += dis2.size();
        }
        else if (dis2.size() == 0)
        {
            pr += dis1.size();
        }
        else
        {
            ll pts = 0;
            for (auto e : dis1)
            {
                if (e < dis2.front())
                {
                    pts++;
                }
            }
            for (auto e : dis2)
            {
                if (e < dis1.front())
                {
                    pts++;
                }
            }
            if (dis1.front() < dis2.front())
            {
                pr += pts;
                // cout << "Game won by " << 'r' << pts << '\n';
            }
            else
            {
                py += pts;
                // cout << "Game won by " << 'y' << pts << '\n';
            }
        }
        
    }
    cout << pr << " " << py << "\n";
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