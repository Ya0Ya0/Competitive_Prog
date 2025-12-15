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
void init() {};
void Solve()
{
    int n, cnt = 0;
    cin >> n;
    // read(ent,n);
    auto ask = [&](int a, int b)
    {
        cnt++;
        if (cnt > n * 2 - 6)
            exit(0);
        cout << "? " << a << " " << b << "\n";
        fflush(stdout);
        int r;
        cin >> r;
        return r;
    };
    deque<int> on;
    vector<int> par(n);
    for (int i = 2; i < n; i++)
    {
        int ans = ask(1, i);
        if (ans == 1)
        {
            on.push_back(i);
            par[i] = 0;
        }
        else
        {
            par[i] = 1;
            on.push_back(i);
            break;
        }
    }
    for (int i = on.back()+1; i < n; i++)
    {
        if (on.size() == 1)
        {
            par[i] = on.front();
            on.pop_front();
            on.push_back(i);
            continue;
        }
        int ans = ask(i, on.front());
        while (ans && on.size() > 1)
        {
            on.pop_front();
            ans = ask(i, on.front());
        }
        par[i] = on.front();
        on.pop_front();
        on.push_back(i);
        continue;
    }
    cout << "! ";
    for(int i = 1; i < n;i++){
        cout << par[i] << " ";
    }
    cout <<"\n";
    fflush(stdout);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}