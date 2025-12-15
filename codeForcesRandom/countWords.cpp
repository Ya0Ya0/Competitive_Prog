#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    fstream st("asd.txt");
    string s;
    int ans = 0;
    while(st>>s)
    {
        ans++;
    }
    cout <<  ans;
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