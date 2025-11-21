#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int k;
    for(int i =0 ;i  < 5;i++)
        for(int j = 0; j <5;j++)
        {
            cin >> k;
            if(k == 1)
            {
                int ans = 0;
                ans+= j+1 < 3?3-j-1 : j+1-3;
                ans+= i+1 < 3?3-i-1 : i+1-3;
                cout << ans;
            }

        }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}