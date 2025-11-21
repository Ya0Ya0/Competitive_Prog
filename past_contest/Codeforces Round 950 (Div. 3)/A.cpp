#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    long ans = 0;
    int n, r;
    cin >> n >> r;
    
    map<char, int> m;
    string s;
    cin >> s;
    char c = 'A';
    while(c <= 'G')
    {
        m[c] = 0;
        c++;
    }
    for (auto c : s)
    {
        m[c]++;
    }
    for (auto [a, b] : m)
    {
        ans += b > r ? 0 : r - b;
    }
    cout << ans <<"\n";
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