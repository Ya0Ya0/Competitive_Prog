#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > a)
        swap(a, b);
    if (d > c)
        swap(c, d);
    for(int i = b;i < a;i++)
    {
        if(i == c) c =-1;
        if(i == d) d= -1;

        if(i == 12)
            i = i%12;
    }
    if((d == -1 && c == -1) || (d!=-1 && c !=-1))
        cout << "No\n";
    else    
        cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}