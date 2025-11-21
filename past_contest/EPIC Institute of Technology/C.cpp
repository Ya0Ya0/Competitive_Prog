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
vector<string> v{"344", "152,124,68", "Biscoe","male","57"};
void Solve()
{
    ifstream f("penguins.csv");
    int c = 0;
    map<string, ll> mp;
    vector<map<string,string>>v;
    vector<string>h;
    int i =0;
    while (f)
    {
        string s;
        f >> s;
        ll idx = s.find(',');
        string k;       
        map <string,string>t; 
        ll z=0;
        while (s!=k)
        {           
            idx = s.find(',');
            k = s.substr(0, idx);
            s = s.substr(idx + 1);
            if(i==0)
                h.push_back(k);
            else{
                t[h[z++]] = k;
            }
        }
        
        if(i == 0)i++;
        else v.push_back(t);        
    }
    ll ans = 0;
    for(int i =0; i < v.size(); i++)
    {
        if(v[i]["sex"] == "male" && v[i]["year"] == "2008")
            ans++;
    }
    f.close();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}