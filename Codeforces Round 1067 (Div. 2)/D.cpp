#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
#define F first 
#define S second  
ll t1,n,m,k;
ll t[3][500005];
string a,b;
int main(){
    cin>>t1;
    while(t1--){
        cin>>n>>a>>b;
        ll p=-1;ll c=0;
        vpll r={},ra={};
        for(int i=0;i<n;i++){
            if(a[i]=='0'){
                for(int j=i+1;j<n;j++){
                    if(a[j]=='0'){
                        r.push_back({i,j});
                        for(int k=i;k<=j;k++){
                            if(a[k]=='0')a[k]='1';
                            else         a[k]='0';
                        }
                        break;
                    }
                }
            }
            if(a[i]=='0'){
                if(i>=2){
                    r.push_back({i-2,i-1});
                    r.push_back({i-2,i});
                }
                else{
                    r.push_back({i+1,i+2});
                    r.push_back({i,i+2});
                }
            }
        }
        ra=r;p=n-1;c=0;
        r={};a=b;
        for(int i=0;i<n;i++){
            if(a[i]=='0'){
                for(int j=i+1;j<n;j++){
                    if(a[j]=='0'){
                        r.push_back({i,j});
                        for(int k=i;k<=j;k++){
                            if(a[k]=='0')a[k]='1';
                            else         a[k]='0';
                        }
                        break;
                    }
                }
            }
            if(a[i]=='0'){
                if(i>=2){
                    r.push_back({i-2,i-1});
                    r.push_back({i-2,i});
                }
                else{
                    r.push_back({i+1,i+2});
                    r.push_back({i,i+2});
                }
            }
        }
        reverse(r.begin(),r.end());
        cout<<r.size()+ra.size()<<"\n";
        for(auto u : ra)cout<<u.F+1<<" "<<u.S+1<<"\n";
        for(auto u : r)cout<<u.F+1<<" "<<u.S+1<<"\n";
    }
return 0;
}