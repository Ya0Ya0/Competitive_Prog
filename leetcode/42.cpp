#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int piv = -1, ans = 0, cur,lvl=0;
    stack<int> q;
    for (int i = 0; i < height.size(); i++)
    {
        int num = height[i];
        if (q.empty())
            q.push(i);
        else if (q.size() < 2)
        {
            if (height[q.top()] <= num)
            {
                q.pop();q.push(i);
            }
            else if (height[q.top()] > num)
            {
                q.push(i);
                lvl = num;
            }                   
        }
        else 
        {
            if (height[q.top()] > num)
            {
                q.push(i);
                lvl = num;
            }
            else if (height[q.top()] < num)
            {
                int past = height[q.top()];q.pop();
                while(!q.empty())
                {
                    int mini = min(height[q.top()],num);
                    ans+= (mini - past) * (i-q.top()-1);
                    past = mini;
                    if(num == mini)
                    {                        
                        break;
                    }
                    else
                    {
                        q.pop();
                    }
                }
                q.push(i);

            }
            else
            {
                q.pop();q.push(i);
            }
        }
    }
    return ans;
}

void Solve()
{
    vector<int> a{5,5,1,7,1,1,5,2,7,6};
    vector<int> b{4, 5, 6};
    cout << trap(a);
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}