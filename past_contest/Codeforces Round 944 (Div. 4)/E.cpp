#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    long long n, k, q;
    cin >> n >> k >> q;
    long long kk=q;
    vector<pair<long long, long long>> dis(k);
    for (auto &p : dis)
        cin >> p.first;
    for (auto &p : dis)
        cin >> p.second;
    long long curans = 0;
    long long pos = 0;
    vector<pair<long long, long long>> que(q);
    long long i = 0;
    for (auto &g : que)
    {
        cin >> g.first;
        g.second = i++;
    }
    sort(que.begin(), que.end());
    i = 0;
    unordered_map<long long,long long>ans;
    while (q--)
    {
        long long z = que[i].first;

        while (dis[pos].first < z)
        {
            curans += dis[pos].second;
            pos++;
        }
        if (pos == 0)
        {
             ans[que[i].second]= (long long)(z / (1.0 * dis[pos].first / dis[pos].second));
        }
        else
        {
            long double aux = (1.0 * dis[pos].first - dis[pos - 1].first) / (dis[pos].second - dis[pos - 1].second);
            long long calc = (1.0 * z - dis[pos - 1].first) / aux;
            ans[que[i].second]= curans + calc;
        }
        i++;

        
    }
    for(long long i = 0;i < kk;i++)
    {
        cout << ans[i];
        cout << " ";
    
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