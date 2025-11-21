#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
#define read(name, n)    \
    vector<ll> name(n);  \
    for (auto &e : name) \
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
ll c = 5001;
ll mod = 1e9 + 7;
void Solve()
{
    int n;cin >> n;string s;
    cin >> s;
    int ans =1;
    vector<int>ini(n);
    for(int i =0;i <n;i++)
    {
        ini[i] = s[i]=='i';
    }
    for(int i =1;i <= n;i++)
    {
        vector<int>cur(n+1);
        int val =0;
        int ok = true;
        for(int j =0;j <n;j++)
        {
            val+=cur[j];
            if(s[j] + val%2 != '1')
            {
                if(j+i >n)
                {
                    ok = false;break;
                }
                val++;
                cur[j+i]-=1;
            }
            
        }
        if(ok)ans = max(ans,i);
    }
    cout << ans <<"\n";
}
void init()
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}