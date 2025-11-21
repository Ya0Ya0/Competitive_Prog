#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,k; cin >> n >> k;
    if(n == k)
    {
        for(int i = 0; i < n; i++ )
        {
            cout << n << " ";
            
        }
        cout << "\n";
    }
    else if (k == 1)
    {
        cout << n <<" ";
        n--;
        for(int i = 0; i < n; i++ )
        {
            cout << n << " ";
        }
        cout << "\n";
    }
    else{
        cout << -1 << "\n";
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