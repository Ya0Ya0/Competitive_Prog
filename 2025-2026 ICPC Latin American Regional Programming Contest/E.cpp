// #include "bits/stdc++.h"
// using namespace std;
// #define ll long long
// #define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
// #define all(x) x.begin(), x.end()

// #define read(name, cnt)   \
//     vector<ll> name(cnt); \
//     for (auto &e : name)  \
//         cin >> e;
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

// struct Tree
// {
//     typedef ll T;
//     static constexpr T unit = LONG_LONG_MIN;
//     T f(T a, T b) { return (a + b); } // (any associative fn)
//     map<T,T> s;
//     int n;
//     Tree(int n = 0, T def = unit) : n(n) {}
//     void update(int pos, T val)
//     {
//         for (s[pos += n] = val; pos /= 2;)
//             s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
//     }
//     T query(int b, int e)
//     { // query [ b , e)
//         T ra = unit, rb = unit;
//         for (b += n, e += n; b < e; b /= 2, e /= 2)
//         {
//             if (b % 2)
//                 ra = f(ra, s[b++]);
//             if (e % 2)
//                 rb = f(s[--e], rb);
//         }
//         return f(ra, rb);
//     }
// };


// void Solve()
// {
//     int n;
//     cin >> n;
//     ll mx = 1e9+5;
//     multiset<ll> st;
//     // multiset<ll>k;k.find(2);
//     // st.lower_bound
//     set<ll> ss;
//     read(ent, n);
//     // ll k = ss.lower_bound(2) - ss.begin();
//     Tree t(mx);
//     vector<int> hs;
//     for (int i = 0; i < n; i++)
//     {
//         if (ent[i] > 0)
//             t.update(abs(ent[i]),1);
//         else
//             t.update(abs(ent[i]),(-1));
//         ll tt = (t.query(0,mx));
//         ll q = t.query(0,abs(ent[i])+1);
//         if(q > abs(ent[i]))
//         {
//             hs.push_back(ent[i]);
//         }
//         ll qa = LONG_LONG_MAX;
//         while(hs.size() && t.query(0,hs.back()+1) < hs.back())hs.pop_back();
//         if(hs.size())qa = hs.back();
//         ll ans =  
//     }
// }

// int main()
// {
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tt = 1;
//     // cin >> tt;
//     while (tt--)
//     {
//         Solve();
//     }
// }