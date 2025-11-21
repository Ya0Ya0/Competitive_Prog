#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    long long n;
    long long i= 1;
    while (cin >> n)
    {
        vector<long long> ent(n);
        long long mini =LONG_LONG_MAX , maxi = -1000001;
        for (auto &e : ent)
        {
            cin >> e;
            mini = min(mini, e);
            maxi = max(maxi, e);
        }
        cout <<"Case " << i << ": " <<  mini << " " << maxi <<" " <<(maxi-mini) << "\n";
        i++;
    }
}

long long main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    long long tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}