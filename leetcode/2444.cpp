#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l = 0;
        int r = 0, mik = 0, mak = 0, ini = 0,isL = 0,isR = 0;
        long long ans = 0;
        for(; r < nums.size(); r++)
        {     
            if(nums[r] > maxK)
            {
                
                ini = r + 1;
                l = r + 1;
                mik = -1;
                mak = -1;
                isL = 0;
                isR = 0;
            }                
            if(nums[r] < minK)
            {
                ini = r + 1;
                l = r + 1;
                mik = -1;
                mak = -1;
                isL = 0;
                isR = 0;
            }
            if(nums[r] == minK)
            {
                mik = r;
                isL = 1;
            } 
            if(nums[r] == maxK)
            {
                mak = r;
                isR = 1;
            }
            if(isL && isR)
                ans +=  min(mik,mak)-ini + 1;
        }
        return ans;
        
    }
};
void Solve()
{
    vector<int> t{1,1,1,1};
    long long a = Solution::countSubarrays(t,1,1);
    cout << a;
}

int main ()
{
    int tt = 1; //cin >> tt;
    while(tt--)
    {
        Solve();
    }
}