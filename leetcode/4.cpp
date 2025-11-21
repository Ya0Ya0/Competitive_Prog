#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size()) / 2;
        int c = (nums1.size() + nums2.size()) % 2;
        int lA = 0, rA = nums1.size(), lB = 0, rB = nums2.size();
        if(c == 0)
        {
            return (solve(nums1, nums2, k, 0, nums1.size(), 0, nums2.size()) + solve(nums1, nums2, k - 1, 0, nums1.size(), 0, nums2.size())) / 2;
        }
        else
        {
            return solve(nums1, nums2, k, 0, nums1.size(), 0, nums2.size());
        }
    }
    static double solve(vector<int>& nums1, vector<int>& nums2, int k, int lA, int rA, int lB, int rB)
    {
        if(lA >= rA)
            return nums2[k -lA];
        if(lB >= rB)
            return nums1[k - lB];
        int midA = (lA + rA) / 2, midB = (lB + rB) / 2;
        int valA = nums1[midA], valB = nums2[midB];
        INT_MAX
        if(midA + midB < k)
        {
            if(valA < valB)
                return solve(nums1, nums2, k , midA + 1, rA, lB,rB );
            else
                return solve(nums1, nums2, k , lA, rA, midB + 1 ,rB );
        }
        else
        {
            if(valA > valB)
                return solve(nums1, nums2, k , lA, midA, lB,rB );
            else
                return solve(nums1, nums2, k , lA, rA, lB, midB );
        }
    }
};
void Solve()
{
    vector<int> a{1,2,3}; 
    vector<int> b{4,5,6};
    cout << Solution::findMedianSortedArrays(a,b);
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}