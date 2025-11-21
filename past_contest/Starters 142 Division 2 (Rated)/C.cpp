#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
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
    ll a;
    cin >> a;
    if(a == 1)a++;
    auto is_prime = [](ll z)
    {
        for(ll i = 2; i*i <= z; i++)
        {
            if(z%i == 0)return false;   
        }
        return true;
    };
    ll pr1=-1,pr2=-1;
    
    while(pr1==-1 || pr2==-1)
    {
        if(pr1!=-1 && is_prime(a))
        {
            pr2 = a;
        }
        else if(is_prime(a))
            pr1 = a;
        a++;
    }
    
    ll cube = pr1*pr1*pr1>0?pr1*pr1*pr1 : LONG_LONG_MAX;
    ll ans = min(pr2*pr1,cube);
    cout << ans <<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}