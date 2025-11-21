#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int r;
    cin >> r;
    long ans = 0;

    int min = r, max = r;
    while (min * min * 2 > r * r)
        min--;
    while (max * max < (r + 1) * (r + 1))
        max++;
    for (int i = min; i <= max; i++)
    {
        int cur = i, t = r, l = 0, r = i+1;
        while (r - l > 1)
        {
            int mid = (l + r / 2);

            if (t * t >= cur * cur + mid * mid)
                l = mid;
            else
                r = mid-1;
        }
        int mini = l;
        l = 0;
        r = i ;
        while (r - l > 1)
        {
            int mid = (l + r / 2);
            int tt = t + 1;
            if (tt * tt >= cur * cur + mid * mid)
                r = mid-1;
            else
                l = mid;
        }
        int maxi = l;
        if(mini>maxi)continue;
        ans += 4 * (maxi - mini);
        if (mini == 0)
            ans -= 4;
        if (maxi == i)
            ans -= 4;
    }

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