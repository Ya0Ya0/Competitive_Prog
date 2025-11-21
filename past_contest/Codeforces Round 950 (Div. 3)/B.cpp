#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    int n, f, k;
    cin >> n >> f >> k;
    vector<pair<int, int>> ent(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ent[i].first;
        ent[i].second = i;
    };
    int fav = ent[f - 1].first;
    sort(all(ent));
    reverse(all(ent));
    for (int i = 0; i < k; i++)
    {
        bool ok = false;
        while (ent[i].first == fav)
        {
            i++;
            ok = true;
        }
        if (i > k)
        {
            cout << "MAYBE\n";
            return;
        }
        if (i <= k && ok)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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