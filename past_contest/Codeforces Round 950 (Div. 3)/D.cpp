#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    int n;
    cin >> n;
    vector<ll> ent(n);
    for (auto &e : ent)
    {
        cin >> e;
    }
    ll prev = __gcd(ent[0], ent[1]);
    ll p = -1;
    for (int i = 1; i < ent.size() - 1; i++)
    {
        ll cur = __gcd(ent[i], ent[i + 1]);
        if (cur < prev)
        {
            p = i;
        }
        prev = cur;
    }
    vector<ll> a = ent, b = ent, c = ent;
    if(p == -1)
    {
        cout << "yes\n";return;
    }
    a.erase(a.begin() + p-1);
    b.erase(b.begin() + p);
    c.erase(c.begin() + p+1);

    auto ok = [](vector<ll> z)
    {
        ll prev = __gcd(z[0], z[1]);
        for (int i = 1; i < z.size() - 1; i++)
        {
            ll cur = __gcd(z[i], z[i + 1]);
            if (cur < prev)
            {
                return false;
            }
            prev = cur;
        }
        return true;
    };
    if(ok(a) || ok(b) || ok(c))
        cout << "yes\n";
    else cout << "no\n";
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