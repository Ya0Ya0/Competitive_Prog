#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> ent(n);
    for (auto &e : ent)
    {
        cin >> e;
    }
    int l1 = 0, r1 = n;
    int m = (r1 + l1) / 2;
    if (m <= t)
    {
        r1 = m;
    }
    else
    {
        l1 = m;
    }
    int fff,l = 0 , r = n;
    int F = -1;
    while (r - l > 1)
    {
        int m = (r + l) / 2;
        if (ent[m] <= t)
        {
            l = m;
        }
        else
        {
            r = m;
        }
        if( ent[m] == t)
            F = m;
    }
    if(ent[l] == t)
    {
        cout << 0 << "\n";
        return;
    }
    if(F != -1)
    {
        for(int i = l1 + 1; i < r1; i++)
        {
            if(ent[i] < t)
            {
                swap(ent[i],ent[F]);
                cout << 2 << "\n";
                cout << i+1 << " " << F+1 << "\n";
                swap(ent[i],ent[l]);
                cout << i+1 << " " << l+1 << "\n"; 
                return;
            }
        }
    }



    //asd
    int found = -1;
    for(int i = 0; i < n; i++)
    {
        if(ent[i] == t)
        {
            found = i;
            break;
        }
    }
    swap(ent[l],ent[found]);
    cout << 1 << "\n" << l+1 << " " << found+1 << "\n";
    // l = 0,r = n;
    // while (r - l > 1)
    // {
    //     int m = (r + l) / 2;
    //     if (ent[m] <= t)
    //     {
    //         l = m;
    //     }
    //     else
    //     {
    //         r = m;
    //     }
    //     if( ent[m] == t)
    //         F = m;
    // }
    // cout << ent[l] << "**\n";
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}