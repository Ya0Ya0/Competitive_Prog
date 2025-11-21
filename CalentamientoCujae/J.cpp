#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    map<char,long>n={{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D,',500},{'M', 1000}};
    int i =5;
    while(i--)
    {
        string s;cin >>s;long ans=0;
        for(int j = 0; j < s.length();j++)
        {
            if(j == s.length()-1)ans+=n[s[j]];
            else{
                if(n[s[j]]<n[s[j+1]])ans-=n[s[j]];
                else ans+=n[s[j]];
            }
        }
        cout << ans << "\n";
    }


    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}