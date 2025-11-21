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
void Solve()
{
    int n,m;cin >> n >> m;
    vector<set<ll>>col(m),row(n);
    vector<set<ll>>col2(m),row2(n);
    for(int i =0; i <n;i++)
    {
        for(int j =0; j <m;j++)
        {
            ll a;cin >> a;
            col[j].insert(a);
            row[i].insert(a);
        }
    }
    set<set<ll>> allcol(all(col)),allrow(all(row));
    for(int i =0; i <n;i++)
    {
        for(int j =0; j <m;j++)
        {
            ll a;cin >> a;
            col2[j].insert(a);
            row2[i].insert(a);
        }
    }
    for(auto s : col2)
    {
        if(allcol.find(s)!=allcol.end())
        {
            allcol.erase(s);
        }
        else{
            cout << "No\n";return;
        }
    }
    for(auto s : row2)
    {
        if(allrow.find(s)!= allrow.end())
        {
            allrow.erase(s);
        }
        else{
            cout << "No\n";return;
        }
    }
    cout << "Yes\n";
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