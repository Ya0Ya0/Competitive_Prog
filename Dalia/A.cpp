#include <bits/stdc++.h>
using namespace std;



bool cabe(char mat[15][15],char palabra[],int fila,int columna)
{
    int tam = strlen(palabra);
    int cur = 0;
    bool ans = false;
    for(int j = columna; j < 15; j++)
    {
        if(mat[fila][j] == '0')
            cur = 0;
        else
            cur++;
        if(cur == tam) ans = true;
    }
    return ans;
}
void Solve()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}