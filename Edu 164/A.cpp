#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int m,k,n;
    cin  >> n >> m >> k;
    if( m == 1)
    {
        cout << "NO\n";return;
    }
    int cant = ceil((float)n/m);
    if(k >= n-cant)
        cout << "NO\n";
    else    
        cout << "YES\n"; 
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