#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n;cin >>n;
    vector<int> ent(n);
    for(auto &e : ent)
        cin >> e;
    if(n == 1)
    {
        cout << "-1\n";return;
    }
    int num1 = ent[0];
    int ans = INT_MAX;
    int i = 1,past = -1;
    while(i < n)
    {
        if(ent[i] != num1)
        {
            ans = min(ans,min(n-i-1,i));
            ans = min(ans,i-past-1);
            past = i;
            
        }
        i++;
    }
    if(past == -1)
        cout <<"-1\n";
    else
    {
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}