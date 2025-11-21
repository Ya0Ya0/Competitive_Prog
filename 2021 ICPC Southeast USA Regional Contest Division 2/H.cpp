#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : name)  \
        cin >> e;
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
    ll a, b, n;
    cin >> a >> b >> n;
    n++;
    // read(ent,n);
    // double m = atan2(a, b);
    ll l = 0, r = (n + 1)*2;
    bool found = false;
    ll fx = -1, fy = -1;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        double y = mid*2 * a/b + 1;
        ll sq = mid + (a * mid * 2 + b) / (2 * b);
        if (sq == n)
        {
            found = true;
            fx = mid*2;
            break;
        }
        if (sq >= n)
        {
            r = mid;
        }
        else
            l = mid;
    }
    if (!found)
    {
        ll l = 0, r = (n + 1)*2;
        while (r - l > 1)
        {
            ll mid = (r + l) / 2;
            double x = (mid*2-1)*b / a;
            //ll sq = (ll)(x / 2) + (ll)(mid );
            ll sq = mid + ((mid * 2 - 1) * b) / (2 * a);
            if (sq == n)
            {
                found = true;
                fy = mid*2;
                break;
            }
            if (sq >= n)
            {
                r = mid;
            }
            else
                l = mid;
        }
    }
    if(fx!=-1)
    {
        ll numx,denx,numy,deny,gcd;
        
        numx = (((fx/2) &1)?2 :0);
        denx = 1;
        double temp = (1.0*a*fx+b)/b;
        ll zz = (((ll)(temp/2)) & 1);
        if(zz)
        {
            double k = ceil(temp/2)*2.0*b;
            numy = k - temp*b; 
        }else{
            numy = temp*b - floor(temp/2)*2*b;
        }
        // numy = (((ll)(temp)/2) &1?-1:1) * (temp - ((ll)(temp)/2)*2);
        deny = b;
        gcd = __gcd(numy,deny);
        numy/=gcd;
        deny/=gcd;
        cout << numx-denx <<" "<< denx <<" "<< numy-deny<<" " << deny << "\n";
    }else{
        ll numx,denx,numy,deny,gcd;

        numy = (((fy/2) &1)?2 :0);
        deny = 1;
        double temp =(1.0*fy*b -b)/a;

        ll zz = (((ll)(temp/2)) & 1);
        if(zz)
        {
            numx = ceil(temp/2)*2*a - temp*a; 
        }else{
            numx = temp*a - floor(temp/2)*2*a;
        }

        // numy = (((ll)(temp)/2) &1?-1:1) * (temp - ((ll)(temp)/2)*2);
        denx = a;
        gcd = __gcd(numx,denx);
        numx/=gcd;
        denx/=gcd;
        cout << numx-denx <<" "<< denx <<" "<< numy-deny<<" " << deny << "\n";
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}