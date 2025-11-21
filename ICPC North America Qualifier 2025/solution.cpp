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
    auto query = [](int i, int j)->bool
    {
        cout << "? " << i << " " << j <<"\n";
        fflush(stdout);
        ll r;
        cin >> r;
        return r;
    };
    auto ans = [](pair<int,int>i)
    {
        cout << "! " << i.first << " " << i.second;
        fflush(stdout);
    };
    // int n;
    // cin >> n;
    // read(ent,n);
    auto ck_cuad = [&](int i,int j)->pair<int,int>
    {
        bool r = query(i+1,j);
        if(r)
        {
            r = query(i,j);
            if(r)
            {
                return {i,j};
            }else return {i+1,j};
        }else{
            r = query(i,j+1);
            if(r){
                return {i,j+1};
            }else return {i+1,j+1};
        }

    };
    int r = query(2,2);
    if(r)
    {
        ans(ck_cuad(1,1));
    }else{
        r = query(2,4);
        if(r)
        {
            ans(ck_cuad(1,3));
        }else{
            r = query(4,2);
            if(r)
            {
                ans(ck_cuad(3,1));
            }else{
                ans(ck_cuad(3,3));
            }
        }
    }
}

    int main()
    {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        // ios::sync_with_stdio(false);
        // cin.tie(nullptr);
        int tt = 1;
        // cin >> tt;
        while (tt--)
        {
            Solve();
        }
    }