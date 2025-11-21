#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t;cin >> t;
	while(t--)
	{
	    ll n,q;cin >> n >> q;
	    vector<ll>que(n/2+1);
	    vector<ll>ent;
        priority_queue< ll,vector<ll>,greater<ll>> queue;
        priority_queue< ll> queue1;
	    for(ll i =1; i <= n; i++)
	    {
	        ll z;cin >> z;
	        queue.push(z);
	        if(!(i&1))continue;
	        if(i == 1){
	            que[0] = z;
	            continue;
	        }	        
	        ll sum =0;

	        que[i/2] = sum;
	        
	    }
	    while(q--)
	    {
	        ll qu;cin >> qu;
	        cout << que[qu/2] << " ";
	    }
	}

}
