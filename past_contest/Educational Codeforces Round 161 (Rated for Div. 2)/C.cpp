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
// long long elevar(long long a, long long b)
// {
//     long long r = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             r = r * a;
//         a = a * a;
//         b /= 2;
//     }
//     return r;
// }
// void Solve()
// {
//     int n, m;
//     cin >> n;
//     vector<ll> ent(n), tr(n),tl(n);
//     for (auto &e : ent)
//     {
//         cin >> e;
//     }
//     cin >> m;
//     iota(all(tr), 0);
//     iota(all(tl), 0);
//     tr[0] = 1, tr[n - 1] = n - 2;
//     for (int i = 1; i < n - 1; i++)
//     {
//         ll l = abs(ent[i] - ent[i - 1]);
//         ll r = (ent[i] - ent[i + 1]);

//         if (l < r)
//         {
//             tr[i] = tr[i - 1];
//         }
//         // if (l < r)
//         // {
//         //     ll z = tr[i-1];
//         //     if(z == i)tr[i] = i-1;
//         //     else tr[i] = z;
//         // }
//         // else{
//         //     ll z = tr[i+1];
//         //     if(z == i)tr[i] = i+1;
//         //     else tr[i] = z;
//         // }
//     }
//     for (int i = n - 2; i >= 1; i--)
//     {
//         ll l = abs(ent[i] - ent[i - 1]);
//         ll r = (ent[i] - ent[i + 1]);

//         if (l > r)
//         {
//             tl[i] = tl[i + 1];
//         }
//         // if (l < r)
//         // {
//         //     ll z = tr[i-1];
//         //     if(z == i)tr[i] = i-1;
//         //     else tr[i] = z;
//         // }
//         // else{
//         //     ll z = tr[i+1];
//         //     if(z == i)tr[i] = i+1;
//         //     else tr[i] = z;
//         // }
//     }
//     tr[0] = max(tr[1],1LL);
//     tl[n - 1] = min(tr[n - 2],(ll)(n-2));
//     ll ans;
//     for (int i = 0; i < m; i++)
//     {
//         ans = 0;
//         ll l, r;
//         cin >> l >> r;
//         l--;
//         r--;
//         if (l < r)
//         {
//             ll nl = tl[l];
//             ans+=nl - l;
//             ll nr = lower_bound(all(tl),r) - tl.begin();
//             ans+=min(r - nr);p
//         }
//         ll nl = max(l, tr[l]);
//         ll nr = min(r, tr[r]);
//         ans += max(0LL, nl - l);
//         ans += max(0LL, r - nr);
//         if(l < r)
//         {
//             ans+=( ent[nr] - ent[nl]);
//         }

//         cout << ans << "\n";
//     }
// }

// int main()
// {
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tt = 1;
//     cin >> tt;
//     while (tt--)
//     {
//         Solve();
//     }
// }