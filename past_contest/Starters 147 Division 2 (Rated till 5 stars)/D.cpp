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
vector<bool> crib(201);
void Solve()
{
    int n;
    cin >> n;
    vector<int> ent(n);
    map<int, int> mp;
    bool end = false;
    for (int i = 0; i < n; i++)
    {
        cin >> ent[i];
        if(mp.find(ent[i])!=mp.end() && !end && ent[i]!=1)
        {
            cout << i+1 << " "<<  mp[ent[i]] + 1 <<"\n";
            end = true;
        }
        mp[ent[i]] = i;
    }
    if(end)return;
    for (int i = 4; i <= 200; i++)
    {
        if (crib[i])
        {
            for (auto [a, b] : mp)
            {
                
                if (mp.find(i - a) != mp.end() && a != i-a)
                {
                    cout << b +1<<" " << mp[i-a] +1<<"\n";return;
                }
            }
        }
    }
    cout << -1<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    for (int i = 2; i <= 200; i++)
    {
        if (!crib[i])
            for (int j = i; i * j <= 200; j++)
            {
                crib[i * j] = true;
            }
    }
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}