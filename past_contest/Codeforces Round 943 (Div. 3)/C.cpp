#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n;cin >> n;
    vector<int>ent(n),ans(n);
    for(int i = 1 ; i < n; i++)
    {
        cin >> ent[i];
        if(i != 0)
        {
            ans[i-1] = ent[i]+1; 
        }
        
    }
    cout << ans[0]<<" ";
    for(int i = 1 ; i < n; i++)
    {
        if(ans[i] < ent[i])
            ans[i] = ent[i];
        else
            ans[i] = ceil(1.0*ans[i]/ans[i-1])*ans[i-1]+ent[i];
        cout << ans[i] << " ";
    }
    cout << "\n";
    
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}