#include <bits/stdc++.h>
using namespace std;


void Solve()
{
    long n,k;
    cin >> n >> k;
    if (k>=n-1)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << n << "\n";
    }
}

int main ()
{
    int tt; cin >> tt;
    while(tt--)
    {
        Solve();
    }
}