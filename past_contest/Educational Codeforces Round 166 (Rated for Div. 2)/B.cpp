#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n + 1);

    for (auto &A : a)
        cin >> A;
    for (auto &B : b)
        cin >> B;    
    ll big = b.back();
    ll ans = 1;
    ll dif = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
        if((big <= a[i] && big >= b[i]) || (big >= a[i] && big <= b[i])) dif = 0;
        dif = min(dif, abs(big - a[i]));
        dif = min(dif,abs(big - b[i]));
    }
    ans += dif;
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