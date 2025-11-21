#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], l[N], r[N], ans[N], cnt = 0;
int merge(int l, int r)
{
    int p = 0, i = l, j = r[0];
    while (i < l[0] && j < n)
    {
        if (a[i] < a[j])
            ans[p++] = i++, l[1]++;
        else
            ans[p++] = j++, r[1]++;
    }
    while (i < l[0])
        ans[p++] = i++;
    while (j < n)
        ans[p++] = j++;
    return p;
}
int check(int lo, int hi)
{
    if (lo == hi)
        return 0;
    int mid = (lo + hi) >> 1;
    l[0] = r[0] = mid;
    int p1 = merge(check(lo, mid), merge(check(mid + 1, hi), n - (mid + 1)));
    if (p1 == n)
        return n;
    cnt = min(cnt, p1);
    return p1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    check(0, n - 1);
    if (cnt == n)
    {
        cout << 0;
        return 0;
    }
    cout << n - cnt << "\n";
    sort(ans, ans + cnt);
    for (int i = 0; i < cnt; i++)
        cout << ans[i] + 1 << " ";
    return 0;
}