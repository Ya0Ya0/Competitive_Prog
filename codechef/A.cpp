#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
    //every 10 numbers we have 55
    //multiply 55*n/10 + 
   
    ll a;
    cin >> a;
    while(a--)
    {
        ll x; cin >> x;
        ll ans = x/9 * 45;
        ll z = x-x%9;
        ll div = 10;
        while((int)z/10)
        {
            ll sum =0;
            while(z)
            {
               sum+=z%10;
               z/=10;
            }
            z = sum;
        }
        z = (z+1)%9;
        ll cant = x%9;
        while(cant--)
        {
            ans+= (z++);
            if(z == 10) z = 1;
        }
        cout << ans << "\n";
    }
    
}
