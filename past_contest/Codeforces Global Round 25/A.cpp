#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n;cin >>n;
    int ones = 0;
    string ent;
    cin >> ent;
    for(auto c : ent)
    {
        if(c =='1')
        {
            ones++;
        }
    }
    if(ones == 2)
    {
        for(int i = 1; i < n; i++)
        {
            if(ent[i] == '1' && ent[i-1] =='1')
            {
                cout << "NO\n";
                return;
            }
        }
    }if(ones & 1)
    {
        cout << "NO\n"; return;
    }
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