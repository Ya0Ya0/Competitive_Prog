#include <bits/stdc++.h>
using namespace std;


void Solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << "NO\n";
        return; 
    }
    cout << "Yes\n";
    int count=0;
    for (int i = 0; i <n;)
    {
        if (count != 2)
        {
            count++;
            cout << "A";
            i++;
        }
        else 
        {
            count = 0;
            cout << "B";
        }
        
    }
    cout << "\n";
}

int main ()
{
    int tt; cin >> tt;
    while(tt--)
    {
        Solve();
    }
}