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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n, -1);
    vector<bool> fx(n);
    vector<pair<int, int>> op;
    vector<pair<int, int>> op2;
    for (int i = 0; i < q; i++)
    {
        int c, l, r;
        cin >> c >> l >> r;

        if (c == 1)
        {
            op.push_back({l - 1, r - 1});
            for (int j = l-1; j <= r-1; j++)
            {
                fx[j] = 1;
            }
            continue;
        }
        else
        {
            op2.push_back({l - 1, r - 1});

            continue;
        }
    }

    // set<int>s;
    // for(int j = l;j <=r;j++)
    // {
    //     s.insert(v[j]);
    // }
    // int lst = 0;
    // for(int j = l;j <=r;j++)
    // {
    //     if(v[j]!=k)continue;
    //     while(s.count(lst))lst++;
    //     v[j] = lst;
    //     s.insert(lst);
    // }

    // for (auto [l, r] : op)
    // {
    //     for (int j = l; j <= r; j++)
    //     {
    //         if (!fx[j])v[j] = k;
    //     }
    // }
    for (auto &[l, r] : op2)while(fx[l])v[l] = k+1,l++;
    for (auto &[l, r] : op2)while(fx[r])v[r] = k+1,r--;
    sort(all(op2));
    for (auto [l, r] : op2)
    {
        // int lst = k-1;
        int fs = 0;
        set<int> s;
        for (int j = l; j <= r; j++)
        {
            s.insert(v[j]);
        }
        for (int j = l; j <= r; j++)
        {
            if (fx[j])
                v[j] = k+1;
            else if(v[j] == -1)
            {
                while(s.count(fs))fs++;
                if(fs >= k)
                {
                    s.clear();
                    fs = 0;
                }
                v[j] = fs;
                s.insert(fs);
            }
               
        }
    }

    for (auto e : v)
        cout << (e == -1? k : e) << " ";
    cout << "\n";
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