#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int cur = 0;
        vector<pair<int,int>> segs;
        int ini = -1;
        for(int i  =0; i < colors.size(); i++)
        {
            int nxt = i+1 < colors.size()? i+1:0,prev = i-1 >= 0? i-1:colors.size()-1;
            if(colors[i]!=colors[prev] && colors[i]!=colors[nxt])
            {
                ini = ini == -1?i : ini;
                cur++;
            }
            else
            {
                segs.push_back({cur,ini});
                cur = 0;
            }
            if((i == colors.size()-1) && cur)
            {
                if(segs.size() == 0 || segs[0].second != 0)
                {
                    segs.push_back({cur+1,ini});
                }
                else if(segs[0].second == 0)
                {
                    segs[0].first+=cur;
                }
            }
        }
        for(int i = 0; i < segs.size(); i++)
        {
            if(segs[i].first >= k-2)
            {
                ans+=(segs[i].first+2)-k+1;
            }
        }
        return ans;
    }
};
void Solve()
{
    vector<int> a{0,1,0,1};
    vector<int> b{4, 5, 6};
    cout << Solution::numberOfAlternatingGroups(a,4); 
    
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}