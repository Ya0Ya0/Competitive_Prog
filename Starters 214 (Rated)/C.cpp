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
    int n,k; 
    cin >> n >> k;
    string s;cin >> s;
    k--;
    int sc = 0;
    vector<int>l(n),r(n);
    iota(all(l),-1);l[0] = n-1;
    iota(all(r),1);r[n-1] = 0;
    vector<int>ope;
    for(int i =0;i < n;i++)
    {   
        ope.push_back(k+1);
        if(i&1)
        {
            // sub
            sc -=s[k]-'0';
        }else{
            sc +=s[k]-'0';
        }
        r[l[k]] = r[k];
        l[ r[k]] = l[k]; 
        if(!(i&1))
        {
            
            if(s[l[k]] == '0')
            {
                k = l[k];
            }
            else 
            {
                k = r[k];
            }
        }
        else
        {
            // sub
            if(s[l[k]] == '1')
            {
                k = l[k];
            }
            else 
            {
                k = r[k];
            }
        }
        
        if(sc <= 0)
        {
            cout << -1 <<"\n";return;
        }
    }
    for(auto o : ope)cout << o <<" ";
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