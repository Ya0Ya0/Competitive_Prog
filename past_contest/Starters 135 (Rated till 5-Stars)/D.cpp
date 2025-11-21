#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    int n;
    cin >> n;
    vector<int> ent(n);
    vector<ll> disi(n,LLONG_MAX);
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
        s.insert(i);
    for(auto &e :ent)cin >> e;
    vector<bool> vis(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto [dis, node] = q.top();
        q.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        s.erase(node);
        if (node == n - 1)
        {
            cout << dis << "\n";
            return;
        }
        for (auto i : s)
        {
            if (vis[i])
                continue;
            ll new_dis = dis + abs(node - i) * max(ent[node], ent[i]);
            if(new_dis > disi[i])continue;
            disi[i] = new_dis;
            q.push({new_dis, i});
        }
    }
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