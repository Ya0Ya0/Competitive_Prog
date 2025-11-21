#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
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
   
    vector<int>mat(100);
    iota(all(mat),1);
    
    vector<int>ans(100);
    int ans1 = INT_MAX;
    do{
        sort(all(mat),[](int a,int b){
            return rand() > rand();
        });
        int cur = 0;
        for(int i = 0; i < 100; i++)
        {
            
            int c1=-1,c2=-1,c3=-1,c4=-1;
            if(!(i < 10))
                cur = max(mat[i-10] + mat[i],cur);
            if(!(i%10 == 9))
            {
                cur = max(mat[i+1] + mat[i],cur);
                c2 = 1+1;
            }
            if(!(i%10 == 0))
            {
                cur = max(mat[i-1] + mat[i],cur);
                c3 = i-1;
            }
            if(!(i >= 90))
            {
                cur = max(mat[i+10] + mat[i],cur);
                c4 = i+10;
            }
            

        }
        if(cur < ans1)
            {
                ans1 = cur;
                ans = mat;
            }
    }while(next_permutation(all(mat)));
    cout << ans1 <<"\n";
    for(int i = 0; i < 100;i += 10)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << ans[i] <<" ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}