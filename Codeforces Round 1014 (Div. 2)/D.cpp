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
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<ll, char> arr[3] = {};
    map<char, int> mp;

    for (auto c : s)
    {
        if (c == 'T')
            arr[0].first++;
        else if (c == 'L')
            arr[1].first++;
        else
            arr[2].first++;
    }
    if (arr[0].first == 0 + arr[1].first == 0 + arr[2].first == 0 > 1)
    {
        cout << -1 << "\n";
        return;
    }
    auto df=[](char a,char b)
    {
        string k = "LIT"; 
        char c = 'L';
        int i =0;
        while(a==c || b == c)
        {
            c = k[i++];
            i%3; 
        }
        return c;
    };
    sort(arr, arr + 3);
    reverse(arr, arr + 3);   
    vector<int>ope;
    for (int i = 0; i < n - 1; i++)
    {
        if(s[i]!=s[i+1] && (s[i]==arr[0].second ||s[i+1]==arr[0].second ))
        {
            int n = s[i]!=arr[0].second;
            char c= df(s[i],s[i+1]);            
            int cur = i;
            while(arr[1]!=arr[0])
            {
                ope.push_back(cur);
                if(n)cur+=n;
                ope.push_back(cur);
                if(n)cur+=n;
                arr[1].first++;
                arr[2].first++;
            }

            while(arr[1]!=arr[0] || arr[2]!=arr[0])
            {
                ope.push_back(cur);
                if(cur==i)cur+=n;
                ope.push_back(cur);
                arr[1].first++;
                arr[2].first++;
            }
        }
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