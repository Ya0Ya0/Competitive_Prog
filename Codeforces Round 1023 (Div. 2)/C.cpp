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
    string s;
    cin >> s;
    read(ent, n);
    vector<ll> pre(n+5), suf(n+5);
    
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0')continue;
        pre[i+1] = max(ent[i], pre[i] + ent[i]);
        if(pre[i+1] > k){
            cout << "No\n";
            return;
        }
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if(s[i]=='0')continue;
        suf[i] = max(suf[i + 1] + ent[i], ent[i]);
        if(suf[i] > k){
            cout << "No\n";
            return;
        }
    }
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        
        if(pre[i+1] == k || suf[i] == k)ok = true;
        if (s[i] != '0')
            continue;        
        int sz = 0;
        int j = i;
        while (j < n && s[j] == '0')
        {
            sz++;
            j++;
        }
        ll l = max(0LL,pre[i]), r = max(0LL,suf[i + sz]);
        if ( !ok)
        {
            ok = true;
            ll df = k - (l + r);
            ent[i++] = df;
            while (i < j)
            {
                ent[i] = 0;
                i++;
            }
        }
        else
        {
            while (i < j)
            {
                ent[i] = -1e18;
                i++;
            }
        }
    }
    if(!ok)
    {
        cout <<"No\n";return;
    }
    cout <<"YES\n";
    for(int i =0;i <n;i++)
    {
        cout << ent[i] <<" ";
    }
    cout <<"\n";
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