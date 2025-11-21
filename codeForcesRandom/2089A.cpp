
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
ll c = 5001;
ll mod = 1e9 + 7;
const ll MAXN =1e5+50;
vector<int> sieve(MAXN);
void Solve()
{
    ll n;
    cin >> n;
    ll k = sieve[n/3];
    ll pr = lower_bound(all(sieve),k+1) - sieve.begin();
    vector<int>used(n+1);
    int lst=0;
    cout << pr <<" ";
    used[pr] = 1;
    for(int i = pr-1,z = 1; i >0 && i <= n;z^=1)
    {
        cout << i <<" ";
        used[i] = 1;
        // lst = i;
        if(z)i=pr+ pr-i;
        else  i = pr - (i-pr)-1;
    }
    for(int i =1 ;i <= n;i++)
    {
        if(!used[i])
        cout << i <<" ";
    }
    cout <<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll i = 2; i < MAXN; i++)
    {
        if(sieve[i])continue;
        for (ll j = i; j * i < MAXN; j++)
        {
            sieve[i*j] = 1;
        }
    }
    for(int i =2;i <MAXN;i++)
    {
        sieve[i] = sieve[i-1] +( sieve[i]==0);
    }
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}