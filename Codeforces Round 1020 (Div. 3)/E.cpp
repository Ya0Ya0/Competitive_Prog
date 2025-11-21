#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long elevar(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = r * a;
        a = a * a;
        b /= 2;
    }
    return r;
}
void Solve()
{
    int n,q; 
    cin >> n >> q;
    read(ent,n);
    vector<int>pos(n+1);
    for(int i =0;i < n;i++)
    {
        pos[ent[i]] = i;
    }
    while(q--)
    {
        ll l,r,x;cin >> l >> r >> x;
        l--;r--;
        if(pos[x] < l || pos[x] > r )
        {
            cout << -1 <<" ";continue;
        }
        ll cnt = 0;
        ll mid = (l+r)/2;
        ll bg=0,ls=0,ab =0;
        while(ent[mid]!=x)
        {
            // cnt++;
            
            if(pos[x] < mid)
            {
                bg++;
                if(x>ent[mid])cnt--,ab++;
                r = mid-1;
            }
            else{
                l = mid+1;
                ls++;
                if(x<ent[mid])cnt++,ab++;
            }
            mid = (l+r)/2;
        }
        if(x + bg > n || x - ls < 1)
        {
            cout << -1 <<" ";continue;
        }
        cnt = ab+abs(cnt);
        cout << cnt <<" ";
    }
    cout <<"\n";
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
}