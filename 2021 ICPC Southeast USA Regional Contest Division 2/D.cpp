#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<pair<long double,long double>>name(cnt);for(auto &e : name)cin >> e.first >> e.second;
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
    int n; 
    cin >> n;
    read(ent,n);
    long double cx=0,cy=0;
    for(auto [a,b] : ent)cx+=a,cy+=b;
    cx/=n;cy/=n;
    long double area = 0,curarea = 0;
    for(int i =0;i < n;i++)
    {
        int nxt = (i+1)%n;
        area+= ent[i].first * ent[nxt].second - ent[i].second * ent[nxt].first;
        
    }
    area/=4;
    long double eps = 1e-12;
    cout << fixed << setprecision(9);
    if(area == NAN)eps+=1;
    for(int i =0;i < n;i++)
    {
        int nxt = (i+1)%n;
        curarea+= ent[i].first * ent[nxt].second - ent[i].second * ent[nxt].first;
        curarea+= ent[nxt].first * ent[0].second - ent[nxt].second * ent[0].first;
        if(fabs(curarea/2-area) <= eps)
        {
            cout << ent[nxt].first <<" " << ent[nxt].second <<"\n";
            return;
        }
        if((curarea/2+eps) > area )
        {
            curarea-= ent[nxt].first * ent[0].second - ent[nxt].second * ent[0].first;
            curarea-= ent[i].first * ent[nxt].second - ent[i].second * ent[nxt].first;
            
            long double l =0 , r = 1 ;
            int mx = 0;
            while (true)
            {
                mx++;
                
                long double t = (l+r)/2;
                long double midx = ent[i].first *  (1-t)+t *ent[nxt].first;
                long double midy = ent[i].second * (1-t)+t *ent[nxt].second;
                curarea+= ent[i].first * midy - ent[i].second * midx;
                curarea+= midx * ent[0].second - midy * ent[0].first;
                if(fabs(curarea/2-area) <= eps || mx == 500)
                {
                    cout << midx << " " << midy <<"\n";
                    return;
                }
                if((curarea/2) > area)
                {
                    r = t;
                }else{
                    l = t;
                }
                
                curarea-= ent[i].first * midy - ent[i].second * midx;
                curarea-= midx * ent[0].second - midy * ent[0].first;
            }
            
        }
        curarea-= ent[nxt].first * ent[0].second - ent[nxt].second * ent[0].first;
    }

    
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}