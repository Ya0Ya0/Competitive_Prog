#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int a,b,c,d;
    int i =1;
    while(cin >> a )
    {
        cin >> b >>c >> d;
        int det = a*d - (c*b);
        if(det == 0)det = 1;
        cout <<"Case " << i << ":\n";
        cout << d/det <<" "<< b*(-1)/det  << "\n"<< c*(-1)/det<<" " << a/det << "\n";
        i++;
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