#include <bits/stdc++.h>
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
void Solve()
{
    


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