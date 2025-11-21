#include <bits/stdc++.h>
using namespace std;

 class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        map<int,int>ma;
        for(int i = 0; i < nums.size(); i++)
        {
            int t = target-nums[i];
            if(m.count(t) )
            {
                return vector<int>{m[t],i};
            }
            m[nums[i]] = i;

        }
        return {};
        
    }
};
void Solve()
{
    vector<int> t{1,2,3};
    vector<int> a = Solution::twoSum(t,5);
    for(auto &A : a)
        cout << A;
}

int main ()
{
    int tt = 1; //cin >> tt;
    while(tt--)
    {
        Solve();
    }
}