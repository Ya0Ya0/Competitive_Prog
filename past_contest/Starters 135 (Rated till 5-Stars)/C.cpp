#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    while (b >= k && b / k >= a && b - 1 > a)
    {
        if (b % k == 0)
        {
            b /= k;
            ans++;
        }
        else
        {
            ans += b % k;
            b -= b % k;            
        }
    }
    cout << ans + (b - a) << "\n";
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