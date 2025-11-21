#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<int> ent(n);
    vector<int> ans(n);

    for(auto &e : ent)
    {
        cin >> e;
        
    }
    int cur = 0;
    for (int i = 0; i < ent.size(); i++)
    {
        if(ent[i]>0)
            ans[i]++;
        else{
            ans[cur - ent[i]]++;
        }
        while(ans[cur] == 1)cur++;
        
        cout <<  (cur  - (ent[i] > 0?ent[i]*(-1): ent[i])) << " ";       

    }
    cout << "\n";
    // 2 -1 = 1 + 2 = 3
    // 3-1+1   a-b = c    a-c = b
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