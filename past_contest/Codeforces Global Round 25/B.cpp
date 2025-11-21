#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n,pos;cin >>n >> pos;
    vector<long long> ent(n);
    for(auto &e : ent)
    {
        cin >> e;
    }
    bool can = true;
    long ans = 0, cur = -1;
    long long cow = ent[pos-1];
    for(int i = 0; i < n; i++)
    {
        if(ent[i] == cow && can)
            can = false;
        else if(ent[i] == cow)
            break;
        if(ent[i]>cow)
        {
            if(!can )
                break;
            cur = i==0?-1:0;           
            can = false;        
        }
        cur++;
        ans = max(ans,cur);
        
    }
    cout << ans << "\n";
    
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