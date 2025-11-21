#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) 
{
    if(num.length() <= k)
        return "";
    int j = 0;
    vector <bool> ok(num.length());
    for(int i = 1; i < num.length() && k; i++)
    {
        while (num[j] > num[i] && k)
        {    
            ok[j] = 0;
            j++;
            k--;
        }
    }        
}
void Solve()
{
    vector<int> a{2, 1, 8};
    vector<int> b{4, 5, 6};
    
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}