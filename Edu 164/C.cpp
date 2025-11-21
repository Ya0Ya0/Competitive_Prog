#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string x,y;
    cin >> x >>y;
    int f = 0;
    for(int i = 0; i < x.length(); i++)
    {
        if(x[i] == y[i])
            continue;
        else
        {
            if(x[i]<y[i])
                swap(x,y);
            f = i;
            break;
        }
    }
    for(int i = f+1; i < x.length(); i++)
    {
        if(x[i] > y[i])
            swap(x[i],y[i]);
    }
    cout << x << "\n" << y << "\n";
    
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