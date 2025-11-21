#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> m1, m2;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        m1[z]++;
    }
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        m2[z]++;
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (m1[i] > 1)
            count++;
    }
    if (count >= k)
    {
        count = k;
    }
    int c = count;
    int nor = (k-count)*2;
    vector <int>r;
    for (int i = 1; i <= n; i++)
    {
        
        if (m1[i] > 1 && c)
        {
            cout << i << " " << i << " ";
            c--;
        }
        else if (nor && m1[i] > 0)
        {
            cout << i << " ";
            nor--;
            r.emplace_back(i);
        }
    }
    cout << "\n";
    c = count;
    for (int i = 1; i <= n; i++)
    {
        if (!c)
            break;
        if (m2[i] > 1 )
        {
            cout << i << " " << i << " ";
            c--;
        }
    }
    for(auto R : r)
    {
        cout << R << " ";
    }
    cout << "\n";
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