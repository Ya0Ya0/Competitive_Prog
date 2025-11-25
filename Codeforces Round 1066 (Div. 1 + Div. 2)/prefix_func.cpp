#include"bits/stdc++.h"
using namespace std;

long long elevar(long long a,long long b){
    long long r=1;
    while(b>0){
        if(b & 1)r=r * a ;
        a=a*a ;
        b/=2;
    }
    return r;
}
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j >  0&& s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void Solve()
{
    
    auto k = prefix_function("ababab");
    for(auto e : k)cout << e << " ";
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
/*
    1 - 1
    2  
*/