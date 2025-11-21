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
    // int n;
    // cin >> n;
    // read(ent,n);

    // L, S, Z, I, O, T

    string s;
    cin >> s;
    bool start = false;
    bool tr = false;
    for (int k = 0; k < min(7, (int)s.length()); k++)
    {
        bool bad = false;
        set<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.count(s[i]))
            {
                bad = 1;
                break;
            }
            st.insert(s[i]);
            if ((i + k) % 7 == 0)
            {
                st.clear();
            }
        }
        if (!bad)
        {
            cout << 1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
    // for(auto c : s) JLJSZIOTJ
    // {
    //     mp[c]++;
    //     for(auto &[a,b] : mp)
    //     {
    //         if(abs(mp[c] - b) > 2)
    //         {
    //             cout << 0 <<"\n";return;
    //         }
    //         if()
    //     }
    // }
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