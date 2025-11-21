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
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &A : a)
        cin >> A;
    for (auto &B : b)
        cin >> B;
    ll minus = 0, plus = 0, ac = 0, bc = 0;
    for (int i = 0; i < n; i++)
    {
        if(max(a[i],b[i]) == -1)minus++;
        else if(max(a[i],b[i]) == 0)continue;
        else if(a[i] == 1 && b[i] == 1)
        {
            plus++;
        }
        else if(a[i] == 1 )ac++;
        else if(b[i] == 1 )bc++;
    }
    if(bc > ac)swap(bc,ac);
    while(ac > bc)
    {
        minus -= ac-bc;
        ac = bc;
    }
    if(minus < 0)ac+=-minus;
    else{
        ac-= minus/2;
        bc-= (minus+1)/2;
    }
    while(ac > bc)
    {
        plus -= ac-bc;
        bc = ac;
    }
    if(plus < 0)bc-=-plus;
    else{
        ac+= (plus+1)/2;
        bc+= (plus)/2;
    }
    cout << min(ac,bc) <<"\n";
    // if(res < 0)
    // {
    //     res = abs(res);
    //     if(bc > ac)swap(ac,bc);
    //     if(ac-bc >= res)
    //     {
    //         cout << bc<< "\n";return;
    //     }
    //     res-=(ac-bc);
    //     ac = bc;
    //     cout << ac - (res+1)/2 << "\n";return;
    // }
    // else if(res >= 0)
    // {
    //     if(bc > ac)swap(ac,bc);
    //     if(ac-bc >= res)
    //     {
    //         cout << bc + res<< "\n";return;
    //     }
    //     res-=(ac-bc);
    //     bc = ac;
    //     cout << ac + (res)/2 << "\n";return;
    // }

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