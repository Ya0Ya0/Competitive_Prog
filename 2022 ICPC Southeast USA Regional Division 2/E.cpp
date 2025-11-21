#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)    \
    vector<int> name(cnt); \
    for (auto &e : name)   \
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
    int n;
    cin >> n;
    read(ent, n);
    vector<array<int, 3>> dp(3);
    for(auto &e : ent)e++;
    /*
    0 1 2 
    01 10 02 20 12 21
    012 021 102 120 201 210

    */
    map<int,int>mp;
    for (int i = 0; i < n; i++)
    {
        mp[ent[i]]++;
        vector<int>st{3,1,2};
        for(int j =1;j <=3;j++)
        {
            if(j==ent[i])continue;
            mp[j*10+ent[i]] = max(mp[j*10+ent[i]]+1,mp[j]+1);
            int nxt = (j)%3+1;
            while(nxt==ent[i])nxt = (nxt)%3+1;
            mp[nxt*100+j*10+ent[i]] = max({mp[nxt*100+j*10+ent[i]]+1,mp[nxt*10+j]+1});
            // mp[nxt*10+j*100+ent[i]] = max({mp[nxt*10+j*100+ent[i]]+1,mp[nxt*1+j*10]+1});
        }
    }
    int mx =0;
    for(auto [a,b] : mp)mx = max(mx,b);
    cout << mx <<"\n";
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