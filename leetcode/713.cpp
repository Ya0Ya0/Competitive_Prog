#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long cur = 1;
        long ans = 0, r, l;
        if(k<= 1)
            return 0;
        for (l = 0, r = 0; r < nums.size(); r++) {
            cur *= nums[r];
            if (cur >= k) {
                ans += r - l;
                while (cur >= k) {
                    cur /= nums[l++];                    
                }
            } 
            ans += r - l + 1;           
        }
        
    }
};
void Solve()
{
    vector<int> t{1,2,3};
    long a = Solution::numSubarrayProductLessThanK(t,0);
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