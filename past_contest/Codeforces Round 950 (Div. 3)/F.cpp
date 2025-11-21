#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<tuple<ll, ll, ll>> ent(k);
    int z = 1;
    for (auto &[a, b, c] : ent)
    {
        cin >> a >> b;
        a--;
        b--;
        c = z++;
    }
    auto comp = [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
    {
        auto [a1, a2, k] = a;
        auto [b1, b2, k1] = b;

        if (a2 == b2)
        {
            return a1 > b1;
        }
        return a2 < b2;
    };
    sort(all(ent), comp);
    tuple<ll, ll, ll> cur = {-1, 0, 0};
    vector<int> ans(k + 1);
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        auto &[a, b, z1] = cur;
        auto [r, c, z2] = ent[i];
        if (b == c)
        {
            a = max(a, r);
            if (r == a)
            {
                ans[z2] = 1;
                z1 = z2;
            }
            continue;
        }
        if (r <= a)
        {
            continue;
        }

        res += (n - 1 - a) * (c - b);
        ans[z2] = 1;
        a = r;
        b = c;
        z1 = z2;
    }
    auto &[a, b, z1] = cur;
    res += (m - b) * (n - a - 1);
    cout << res << "\n";
    for (int i = 0; i < k; i++)
    {
        cout << ans[i + 1] << " ";
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