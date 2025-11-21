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
ll ask(ll n)
{
    cout << "? " << n << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}
void ans(ll a, ll b = -1)
{
    if (b == -1)
    {
        cout << "! " << -1 << "\n";
    }
    else
        cout << "! " << a << " " << b << "\n";
    cout.flush();
}
void Solve()
{
    ll k, n;
    cin >> n >> k;
    // read(ent,n);
    vector<ll> a, b, c;
    for (int i = 0; i < k; i++)
    {
        a.push_back(ask(i + 1));
    }
    for (int i = 0; i < k; i++)
    {
        b.push_back(ask(n - i));
    }
    // int it = 0;
    // while (a.front() != b[it])
    // {
    //     it++;
    // }
    // for (int i = it; i < k; i++)
    // {
    //     c.push_back(b[i]);
    // }
    // for (int i = 0; i < it; i++)
    // {
    //     c.push_back(b[i]);
    // }
    int ok = -1;
    for (int i = 0; i < k; i++)
    {
        if (a[i] != b[i]){
            ok = i;break;}
    }
    if (ok == -1 && n == 2 * k)
    {
        ans(k / 2, k / 2);
    }
    else if (ok == -1)
    {
        ans(-1);
    }
    else
    {
        ll l = 0, r = (n + k - 1) / k;
        ll look = a[ok];
        auto ck = [&](ll mid) -> bool
        {
            ll z = ask(k * mid + ok),nxt = ok+1;
            if (ok == n - 1)
                nxt =0;
            ll y = ask(k * mid + nxt);
            if (z == a[ok] && a[y] == a[ok+1])
                return true;
            else
                return false;
        };
        while (r - l > 0)
        {
            
            ll mid = (l + r) / 2;
            if(k*mid + ok>=n){l =(n + k - 1) / 2;break; }
            if (ck(mid))
                l = mid;
            else
                r = mid-1;
            
        }
        // if (l == (n + k - 1) / 2)
        // {
        //     ll l = 0, r = (n + 2 * k - 1) / k;
            

        //     while (r - l > 1)
        //     {
        //         ll mid = (l + r) / 2;
        //         if (ck(mid))
        //             l = mid;
        //         else
        //             r = mid;
        //     }
        // }
        ll pos = k * l + ok, pos_b;
        for (int i = 0; i < k; i++)
        {
            if (b[i] == a[ok])
                pos_b = i;
        }
        ll anss = 0;
        for (int i = 1; i <= k; i++)
        {
            ll res = ask(pos - i);
            if (res == b[((pos_b - i + k) % k)])
            {
                continue;
            }
            else
            {
                anss = pos - i;
                break;
            }
        }
        ans(anss + 1, n - (anss + 1));
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