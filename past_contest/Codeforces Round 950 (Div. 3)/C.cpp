#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

void Solve()
{
    ll n;
    cin >> n;
    vector<ll> og(n), res(n);
    for (auto &e : og)
    {
        cin >> e;
    }
    for (auto &e : res)
    {
        cin >> e;
    }
    int mod;
    cin >> mod;
    vector<ll> ch(mod);
    map<ll,ll> m;
    for (auto &e : ch)
    {
        cin >> e;        
    }
    for(int i = 0; i <n; i++)
    {
        if(og[i]!=res[i])m[res[i]]++;
        else if(!m.count(res[i]))m[res[i]] = 0;
    }
    int ite = n - 1;
    bool modi = false;
    for(int i = mod-1; i >=0; i--)
    {
        if(!m.count(ch[i]) && !modi)
        {
            cout <<"No\n";return;
        }
        if(m.count(ch[i]))
        {
            modi = true; 
            m[ch[i]] = m[ch[i]] > 0?m[ch[i]]-1 : m[ch[i]];
        }
    }
    for(auto [a,b] : m)
    {
        if(b > 0)
        {
            cout <<"No\n";return;
        }
    }
    cout <<"YES\n";return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}