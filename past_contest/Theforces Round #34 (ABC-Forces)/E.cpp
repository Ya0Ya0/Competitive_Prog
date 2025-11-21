// #include "bits/stdc++.h"
// using namespace std;
// #define ll long long
// #define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
// #define all(x) x.begin(), x.end()
// struct custom_hash
// {
//     static uint64_t splitmix64(uint64_t x)
//     {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// ll mod = 998244353;
// long long elevar(long long a, long long b)
// {
//     long long r = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             r = (r * a) % mod;
//         a = (a * a) % mod;
//         b /= 2;
//     }
//     return r;
// }
// const ll inf = 100007;

// ll factorial[inf];
// void Solve()
// {
//     int n;
//     cin >> n;
//     map<ll, ll> mp;
//     for (int i = 0; i < n; i++)
//     {
//         ll a;
//         cin >> a;
//         mp[a]++;
//     }
//     auto bic = [&](ll a)
//     {
//         return (factorial[n - 1] * elevar(factorial[a], mod - 2) % mod) * elevar(factorial[n - 1 - a], mod - 2) % mod;
//     };
//     if ((*mp.rbegin()).first - (*mp.begin()).first != 1 && (*mp.rbegin()).first - (*mp.begin()).first != 0)
//     {
//         cout << 0 << "\n";
//         return;
//     }
//     else
//     {
//         ll ans = n;
//         if (mp.size() > 1)
//         {

//             ll f = (*mp.begin()).second;
//             ans = ans * bic(f);
//         }
//         else{
//             ll f = (*mp.begin()).first
//         }
//         cout << ans << "\n";
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     factorial[1] = 1;
//     for (int i = 2; i < inf - 2; i++)
//     {
//         factorial[i] = (factorial[i - 1] * i) % mod;
//     }
//     int tt = 1;
//     cin >> tt;
//     while (tt--)
//     {
//         Solve();
//     }
// }