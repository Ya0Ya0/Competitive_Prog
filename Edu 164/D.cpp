#include <bits/stdc++.h>
using namespace std;

void Solve()
{

    int i = 0, j = 0;
    int n;
    cin >> n;
    long long ans=0;
    vector<int> ent(n);
    for (auto &e : ent)
        cin >> e;
    for (i = 0, j = 0; i < n; i++)
    {
        j = i;
        map<int, int> m;
        long long sum = 0;
        while (j < n)
        {
            m[ent[j]]++;
            sum += ent[j];
            int mayor = m.rbegin()->first;
            if(mayor > sum-mayor)
            {
                ans = (ans+mayor) % 998244353;
            }
            else
            {
                ans = (ans + sum/2 + sum % 2) % 998244353;
            }
            j++;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}