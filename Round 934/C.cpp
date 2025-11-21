#include <bits/stdc++.h>
using namespace std;


void Solve()
{
    int n;
    cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++)
    {
        int z; cin >> z;
        m[z]++;
    }
    int lib=1;
    for(int i = 0; i < n; i++)
    {
        if(m[i]<i+1)
        {
            
        }
        else
        {
            cout << i << "\n";
            break;
        }
            
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