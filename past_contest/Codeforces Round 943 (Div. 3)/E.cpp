#include <bits/stdc++.h>
using namespace std;

long long aux(vector<pair<int,int>>&cells,int f,int cur,map<pair<int,int>,int>&m)
{
    if(f == 0)
    {

    }
    m[cells[cur]]++;
    long long ans1 = aux(cells,f-1,cur+1,m);
    m[cells[cur]]--;
    long long ans2 = aux(cells,f,cur+1,m);
    return max(ans1,ans2);
}
void Solve()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}