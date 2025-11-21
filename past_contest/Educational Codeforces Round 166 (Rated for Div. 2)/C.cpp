#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    ll n, m;
    cin >> n >> m;
    ll total = n + m + 1;
    vector<ll> test(total), pro(total);
    ll T = 0, P = 0;
    ll skill = 0;
    for (auto &e : pro)
        cin >> e;

    for (auto &e : test)
        cin >> e;
    deque<ll> ucP, ucT;
    for (ll i = 0; i < total - 1; i++)
    {
        if (pro[i] >= test[i])
        {
            if (P < n)
            {
                P++;
                skill += pro[i];
            }
            else
            {
                ucP.push_back(i);
                T++;
                skill += test[i];
            }
        }
        else
        {
            if (T < m)
            {
                T++;
                skill += test[i];
            }
            else
            {
                ucT.push_back(i);
                P++;
                skill += pro[i];
            }
        }
    }
    T = 0, P = 0;
    for (ll i = 0; i < total - 1; i++)
    {
        if ((pro[i] >= test[i] && P < n) || T >= m)
        {
            ll temp = skill - pro[i];
            while (!ucP.empty() && ucP.front() <= i)
                ucP.pop_front();
            if (!ucP.empty())
            {
                temp += pro[ucP.front()];
                temp -= test[ucP.front()];
                temp += test[total-1];
            }
            else
                temp += pro[total-1];
            cout << temp << " ";
            P++;
        }
        else
        {
            ll temp = skill - test[i];
            while (!ucT.empty() && ucT.front() <= i)
                ucT.pop_front();
            if (!ucT.empty())
            {
                temp += test[ucT.front()];
                temp -= pro[ucT.front()];
                temp += pro[total-1];
            }
            else temp += test[total-1];
            cout << temp << " ";
            T++;
        }
    }
    cout << skill << "\n";
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