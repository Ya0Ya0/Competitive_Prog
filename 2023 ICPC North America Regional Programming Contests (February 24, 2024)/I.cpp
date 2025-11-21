#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, p, q;
    cin >> n >> m >> s >> p >> q;
    vector<int> pp(p), qq(q);
    for (auto &e : pp)
        cin >> e;
    for (auto &e : pp)
        e--;
    s--;
    for (auto &e : qq)
        cin >> e;
    for (auto &e : qq)
        e--;
    int ans = 0;
    int fs = 1;
    set<int> rb{pp.begin(), pp.end()}, qqq{qq.begin(), qq.end()};
    int l = -1, r = -1;
    for (int i = 0; i < (n + m - 1) / m; i++)
    {
        int cur = 0;
        set<int> cur_q, comp, combined;
        for (int j = 0; j < m && i * m + j < n; j++)
        {
            if (rb.count(i * m + j))
            {                
                combined.insert(i * m + j);
            }
            if (qqq.count(i * m + j))
            {
                cur_q.insert(i * m + j);
                if (combined.count(i * m + j))
                    combined.erase(i * m + j);
                else
                    combined.insert(i * m + j);
            }
            else
                comp.insert(i * m + j);
        }        
        cur = min(min(1 + (int)cur_q.size(), 1 + (int)comp.size()), (int)combined.size());
        ans += cur;
        if (cur != 0)
        {
            r = i;
            if (l == -1)
                l = i;
        }
    }
    if (ans != 0)
        ans += min(abs(s - l), abs(s - r)) + abs(r - l);
    cout << ans << "\n";
}
