#include "bits/stdc++.h"
using namespace std;
#define ll long long

#define read(name, cnt) vector<int>name(cnt);for(auto &e : ent)cin >> e;

int min_sum_after_swap(vector<int> A, int N)
{
    //Take the first element

    int lst = A.front();
    //Sort so we can start checking for the first element towards bigger elements
    sort(A.begin(),A.end());
    
    bool ok = false;
    // Finding the first element before the swaps using binary search 
    auto ite = lower_bound(A.begin(),A.end(),lst);
    //Going foward until the next element is bigger than 3 times current element or until the bigger element
    while(next(ite)!=A.end())
    {        
        auto z = next(ite);
        
        if(*z > (*ite)*3)
        {
            break;
        }
        
        ite = z;
    }
    ll ans = accumulate(A.begin(),A.end(),0LL) - *ite;
    return ans;
}
void Solve()
{
    int n; 
    cin >> n;
        n++;

    read(ent,n);
    
    cout << min_sum_after_swap(ent,n)  << " == " << min_sum_after_swap(ent,n) << "\n";
    
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
    cout << "OK\n";
}