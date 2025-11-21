#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    //365 687
    int a,b,z=1;
    while(cin >>a)
    {
        cin >>b;
        int ans=0;
        
        while(a%365 || b%687)
        {
            ans+=1;
            a+=1;b++;
        }
        cout <<"Case "<<z++<<": "<< ans << "\n";
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}