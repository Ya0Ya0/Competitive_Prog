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
    ll n, q;
    cin >> n >> q;
    vector<ll> per(n);
    for (ll i = 1; i < n; i++)
    {
        ll a;
        cin >> a;
    }
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> per[i];
        mp[per[i]] = i;
    }
    set<ll> f;
    for (ll i = 1; i * 2 <= n; i++)
    {
        if (mp[i * 2] < mp[i])
        {
            f.insert(i * 2);
            f.insert(i);
        }
    }
    vector<ll>que(2*q);
    for(ll i = 0; i < q*2; i+=2)
    {
        cin >> que[i] >> que[i+1];
    }
    ll z = 0;
    while (z < q*2)
    {
        ll l = que[z]-1, r = que[z+1]-1;
        // cin >> l >> r;
        swap(mp[per[l]], mp[per[r]]);
        swap(per[l],per[r]);
        l = per[l];
        r = per[r];
        queue<ll> qp;
        qp.push(l);
        qp.push(r);
        while(!qp.empty())
        {
            auto cur  =qp.front();
            qp.pop();
            bool ok = false;
            if(mp[cur] > mp[cur*2] && cur*2 <= n)
            {
                f.insert(cur);
                f.insert(cur*2);
                ok = 1;
            }
            if( mp[cur] < mp[cur/2])
            {
                f.insert(cur);
                f.insert(cur/2);
                ok = 1;
                
            }
            if(mp[cur] > mp[cur*2+1] && cur*2+1 <= n)
            {
                f.insert(cur);
                f.insert(cur*2+1);
                ok = 1;
               
            }
            if(ok)continue;
            f.erase(cur);
            if(f.find(cur*2)!=f.end())
            {
                qp.push(cur*2);
                f.erase(cur*2);
            }
            if(f.find(cur*2+1)!=f.end())
            {
                qp.push(cur*2+1);
                f.erase(cur*2+1);
            }
            if(f.find(cur/2)!=f.end())
            {
                qp.push(cur/2);
                f.erase(cur/2);
            }
        }
        if (f.empty())
        {
            cout << "yes\n";
        }
        else
            cout << "no\n";
        z+=2;
    }
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