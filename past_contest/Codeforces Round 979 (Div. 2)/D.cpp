#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt)   \
    vector<ll> name(cnt); \
    for (auto &e : ent)   \
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
    int n, q;
    cin >> n >> q;
    read(ent, n);
    // for(auto e : ent)cout << e <<  " ";
    vector<pair<ll, ll>> segs;
    set<pair<ll, ll>> get;
    // iota(all(get),0);
    string s;
    cin >> s;
    // auto parent = [&](auto self,ll a )
    // {
    //     if(par[a] == a)return a;
    //     else return self(self,par[a]);
    // };
    // auto merge = [&](ll a,ll b)
    // {
    //     if(parent(parent,a) == parent(parent,b))return;
    //     else{
    //         par[b] = a;
    //     }
    // };
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (s[i] == s[i - 1])
            r++;
        else if (s[i - 1] == 'R' && s[i] == 'L')
        {
            r++;
        }
        else
        {
            get.insert({l, r});
            l = r;
        }
        if (i == n - 1)
            get.insert({l, r});
    }

    set<ll> w;
    for (ll i = 0, l = 0, r = 0; i < n; i++)
    {
        r = max(r, ent[i]);
        l = min(l, ent[i]);
        if (i == r - 1 || i == n - 1)
        {
            while (segs.size() && segs.back().second >= l)
            {
                l = segs.back().first;
            }
            segs.push_back({l, r});
            l = r + 1;
        }
    }
    int p =0;
    for (auto [a, b] : segs)
    {
        auto z =get.lower_bound({a,0});
        if((*z).second < b)
        {
            w.insert(p);
        }
        p++;
    } // for(auto [a,b] : segs)cout << a << " " << b << "\n";
    for(int i =0;i <q;i++)
    {
        int q;cin >> q;
    }
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