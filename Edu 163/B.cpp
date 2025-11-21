#include <bits/stdc++.h>
using namespace std;


void Solve()
{
    int tam; cin >> tam;
    vector <int> ent(tam);
    for (auto &e : ent)
    {
        cin >> e;
    }
    int menor = 0;
    for (auto &e : ent)
    {
        if (e > 9)
        {
            if (menor > (e % 100)/10)
            {
                cout << "NO\n";
                return;
            }
            else 
            {
                menor = (e % 100) / 10;
            }       
        }
        if (menor > e % 10)
        {
            cout << "NO\n";
            return;
        }
        else 
        {
            menor = e % 10;
        }
        

    }
    cout << "YES\n";
}

int main ()
{
    int tt; cin >> tt;
    while(tt--)
    {
        Solve();
    }
}