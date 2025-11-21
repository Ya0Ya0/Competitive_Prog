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
    vector<ll> dis;
    vector<pair<ll, ll>> pts;
    ll px, py;
    cin >> px >> py;
    pts.push_back({px, py});
    dis.push_back(px * px + py * py);
    double m1 = (pts[0].second + .0) / (pts[0].first);
    double rm = -1 / m1;
    auto cuad = [&](pair<ll, ll> p)
    {
        if (p.first > 0 && p.second > 0)
            return 1;
        if (p.first < 0 && p.second > 0)
            return 2;
        if (p.first > 0 && p.second < 0)
            return 4;
        if (p.first < 0 && p.second < 0)
            return 3;
        return 0;
    };
    auto f = [&](ll x)
    {
        return rm * (x - pts[0].first) + pts[0].second;
    };
    for (int i = 0; i < 2; i++)
    {
        ll x, y;
        cin >> x >> y;
        pts.push_back({x, y});
        dis.push_back((x - px) * (x - px) + (y - py) * (y - py));
    }
    if (dis[1] > dis[0] || dis[2] > dis[0])
    {
        cout << "NO\n";
    }
    else if (dis[1] == dis[0] || dis[2] == dis[0])
    {
        double cy = f(pts[1].first);
        if (dis[1] == dis[0])
        {
            if (rm < 0 && cuad(pts[1]) == 1 && cy < pts[1].second)
            {
                cout << "NO\n";
            }
            if (rm < 0 && cuad(pts[1]) == 3 && cy > pts[1].second)
            {
                cout << "NO\n";
            }
            if (rm > 0 && cuad(pts[1]) == 2 && cy > pts[1].second)
            {
                cout << "NO\n";
            }
            if (rm > 0 && cuad(pts[1]) == 4 && cy < pts[1].second)
            {
                cout << "NO\n";
            }
        }
        cy = f(pts[2].first);
        if (dis[2] == dis[0])
        {
            if (rm < 0 && cuad(pts[2]) == 1 && cy < pts[2].second)
            {
                cout << "NO\n";
            }
            if (rm < 0 && cuad(pts[2]) == 3 && cy > pts[2].second)
            {
                cout << "NO\n";
            }
            if (rm > 0 && cuad(pts[2]) == 2 && cy > pts[2].second)
            {
                cout << "NO\n";
            }
            if (rm > 0 && cuad(pts[2]) == 4 && cy < pts[2].second)
            {
                cout << "NO\n";
            }
        }
        double cyy = f(pts[1].first);
        if(dis[1] == dis[0] && dis[2] == dis[0] && cy == pts[2].second && cyy == pts[1].second)
        {
            cout << "NO\n";return;
        }
        cout << "YES\n";
        // double m2 = (pts[1].second - pts[0].second+.0) / (pts[1].first - pts[0].first);
    }
    else
    {
        cout << "YES\n";
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
    while (tt--)
    {
        Solve();
    }
}