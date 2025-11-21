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
    int n; 
    cin >> n;
    int a =0,b=n-1;
    read(ent,n);
    ll ok = true;
    ll lst = 0;
    string ans = "";
    for(int i =0;i < n;i++)
    {
        if(a > b)
            break;
        if(ent[a] == ent[b])
        {
            ans+="L";break;
        }
        ll k = ent[a],j = ent[b];
        ll z = max(k,j);
        if(lst > z)
        {
            if(k < j)
            {
                ans+="LR";
                ok = false;
                a++;b--;
                lst =j;
            }
            else 
            {
                ans+="RL";
                ok = true;
                b--;a++;
                lst = k;
            }         
        }else{
            if(k > j)
            {
                ans+="LR";
                ok = false;
                a++;b--;
                lst =j;
            }
            else 
            {
                ans+="RL";
                ok = true;
                b--;a++;
                lst = k;
            }           
        }
       
    }
    cout << ans << "\n";
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