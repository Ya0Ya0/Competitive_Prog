#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *prev, *next = ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int val = (l1->val + l2->val + carry);
            carry = val / 10;
            next->val = val % 10;
            next->next = new ListNode();
            prev = next;
            next = next->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l = l1 != NULL ? l1 : l2;
        if (l == NULL)
            prev->next = NULL;
        else
        {
            while (l != NULL)
            {
                int val = (l->val + carry);
                carry = val / 10;
                next->val = val % 10;
                next->next = new ListNode();
                prev = next;
                next = next->next;
                l = l->next;
            }
            if (carry)
            {
                next->val = carry;
            }
            else
            {
                prev->next = NULL;
            }
        }
        return ans;
    }
};
void Solve()
{
    vector<int> t{1, 2, 3};
    ListNode *a = Solution::addTwoNumbers(new ListNode(1, new ListNode(3, new ListNode(9))), new ListNode(2));
    // for (auto &A : a)
    //     cout << A;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}