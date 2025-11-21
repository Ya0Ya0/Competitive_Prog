#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    long long n;
    cin >> n;
    long long ope = 0,ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ope++;
        long long k = n*i;
        long long z = n*(n+1);
        long long cant = (z)/2;
        if(cant >= k)
        {
            if(i>1)
            {
                ope++;ans+=i-1;
            }
            ope++;
            
            ans += cant;
        }
        else
        {
            ans+= n*i;
        }
    }
    cout << ans << " " << ope  <<"\n";
    string s;
    for(long long i = 1; i <= n; i++)
    {
        char c = (i) + '0';
        s += ' ';
        s += c;
    }
    for(long long i = 1; i <= n; i++)
    {
        if(ope){
            cout<< 1 <<" " << i << s  <<"\n" ;        
            ope--;
        }
        
    }
    for(long long i = 1; i <= n; i++)
    {
        if(ope){
            cout << 2 <<" " << i << s <<"\n" ;        
            ope--;
        }     
    }
   
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