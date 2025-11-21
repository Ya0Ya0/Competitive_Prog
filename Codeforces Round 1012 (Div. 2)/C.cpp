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
vector<pair<int, int>> dis;
    
    vector<pair<int, int>> emp;
    ll mx = 50009;
void Solve()
{
    
    
    set<pair<int, int>> seen;
    int n;
    cin >> n;
    read(ent, n);

    
    for (int i = 0, empi = 0, disi = 0; i < n; i++)
    {
        if (ent[i] == 1)
        {
            while (seen.count(dis[disi]))
                disi++;
            seen.insert(dis[disi]);
            cout << dis[disi].first << " " << dis[disi].second << "\n";
        }
        else
        {
            while (seen.count(emp[empi]))
                empi++;
            seen.insert(emp[empi]);
            cout << emp[empi].first << " " << emp[empi].second << "\n";
        }
    }
}
/*
1 1
1 2
2 1
1 4
4 1
1 5
1 1
1 4
4 1
1 2
2 1*/
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;

    int op = 0;
    for (int i = 0; i < mx + 5; i++)
    {
        for (int j = 0, k = i; j <= i; j++, k--)
        {

            if (!((k % 3 == 0) || (j % 3 == 0)))
            {
                if((k-2)%3 == 0 && (j-2)%3 == 0 )continue;
                if((k-1)%3 == 0 && (j-2)%3 == 0 && j>2 && k>1){
                    dis.push_back({j-2, k-1});
                }
                dis.push_back({j, k});
            }
            

            if (dis.size() > mx )
                break;
        }
        if (dis.size() > mx)
            break;
    }
    for (int i = 1; i < mx + 5; i+=3)
    {
        for (int j = 1, k = i; j <= i; j+=3, k-=3)
        {
            if (((k - 1) % 3 == 0) && ((j - 1) % 3 == 0))
            {
                emp.push_back({j, k});
            }
            if(emp.size() > mx)break;
        }if(emp.size() > mx)break;
    }

    
    while (tt--)
    {
        Solve();
    }
}