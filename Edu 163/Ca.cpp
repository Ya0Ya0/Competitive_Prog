#include <bits/stdc++.h>

using namespace std;

void bfs(int row, int pos,  vector <vector<bool>> &visited,vector <vector<char>> &ent )
{
    
    if (visited[row][pos])
    {
        return;
    }
    else
    {
        visited[row][pos] = true;
        int nextR = row == 1 ? 0 : 1;
        int nextP = ent[nextR][pos] == '>'?pos+1:pos-1;
        bfs(nextR,nextP,visited,ent);
        if(ent[row][pos+1] == '>')
        {
            bfs(row,pos+2,visited,ent);
        } 
    }
    
}
void Solve()
{
    int n;
    cin >> n;
    vector <vector<char>> ent(2,vector<char>(n));
    vector < vector <bool> > visited(2,vector<bool>(n));
    for(int i = 0; i < n; i++)
    {
        cin >> ent[0][i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> ent[1][i];
    }
    int row=0,col=0;
    while(row!=1 && col!=n)
    {
        if(!visited[row][col])
        {
            visited[row][col] = true;
        }
        else continue;
    }





    bfs(0,0,visited,ent);
    if(visited[1][n-1])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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