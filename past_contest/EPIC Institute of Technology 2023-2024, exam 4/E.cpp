#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()
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
int GetHash(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = (res * 42 + s[i] - 'a' + 1) % 1000;
  }
  return res;
}
void Solve()
{
    string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaya";
    string b = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaai";
    cout << a <<"\n"<<b;return;
    string s = "";
    for(int i = 0; i < 30; i++)
        s = "a" + s;
    auto create = [](string s) ->string
    {
        bool ok = false;
        string k = s;
        int idx = s.size()-1;
        if(k == "")return (k+"a");
        while(k[idx] == 'z')
        {
            k[idx--] = 'a';
            if(idx == -1)
            {
                k = "a"+ k;
                return k;
            }
        }      
        k[idx]++;
        return k;
    };
    map <int,string> mp;
    while(true)
    {
        s = create(s);
        if(mp.count(GetHash(s)))
        {
            cout << s << " "<< mp[GetHash(s)];
            break;
        }
        mp[GetHash(s)] = s;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        Solve();
    }
}