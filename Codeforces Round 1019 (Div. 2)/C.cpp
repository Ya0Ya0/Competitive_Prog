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
    ll n, k;
    cin >> n >> k;
    read(ent, n);
    for (auto &e : ent)
        if (e <= k)
            e = 1;
        else
            e = -1;
    vector<ll> on(n + 1), onpos, revpos, rev(n + 1);
    // for(int i =0;i <n;i++)
    // {
    //     pre[i+1] = pre[i]+ent[i];
    // }
    map<ll, vector<ll>> onmp, revmp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            on[i] = ent[i];
            continue;
        }
        on[i] = on[i - 1] + ent[i];
    }
    ll c = 0;
    ll fs =-1,ls = -1;

    for (int i = 0; i < n-1; i++)
    {
        if(on[i]>=0 && fs==-1)
        {
            fs =i;
        }
        if (on[i] > 1)
        {
            cout << "YES\n";
            return;
        }
        if (on[i] == 0)
            c++;
    }
    if (c >= 2 || (c==1 && on[n-2] >0))
    {
        cout << "YES\n";
        return;
    }
    c = 0;
    
    for (int i = n - 1; i > 0; i--)
    {
        rev[i] = rev[i + 1] + ent[i];
        revmp[rev[i]].push_back(i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        if(rev[i]>=0 && ls==-1)
        {
            ls =i;
        }
        if (rev[i] > 1)
        {
            cout << "YES\n";
            return;
        }
        if (rev[i] == 0)
            c++;
    }
    if (c >= 2 || (c==1 && rev[1]>0))
    {
        cout << "YES\n";
        return;
    }
    if(ls!=-1 && fs!=-1 && ls - fs > 1)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}