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
    int n, q;
    cin >> n >> q;
    vector<int> ent(n);
    vector<int> pre(n + 1);
    vector<int> ope;
    for (int i = 0; i < n; i++)
    {
        cin >> ent[i];
        if (i < 1)
            continue;
        pre[i] = pre[i] + (ent[i] != ent[i + 1]);
        if (ent[i] != ent[i - 1])
        {
            ope.push_back(ent[i]);
        }
    }
    // vector<int>tw,on;
    // for(int i =1; i <ope.size()-1;i++)
    // {
    //     if((ope[i] > ope[i+1] && ope[i] > ope[i-1]) || (ope[i] < ope[i+1] && ope[i] < ope[i-1]))
    //     {
    //         tw.push_back(min(abs(ope[i] - ope[i+1]),abs(ope[i]-ope[i+1])));
    //     }
    // }
    for (int z = 0; z < q; z++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        int c = v - pre[r] - pre[l];
        if (c <= 0)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<int> df = {ent[l - 1]};
        stack<int> stk;
        for (int i = l; i < r - 1; i++)
        {
            if (ent[i] != ent[i - 1])
            {
                df.push_back(ent[i]);
            }
        }
        vector<int> pts;
        // for (int i = 0; i < df.size(); i++)
        // {
        //     if ((ope[i] > ope[i + 1] && ope[i] > ope[i - 1]) || (ope[i] < ope[i + 1] && ope[i] < ope[i - 1]))
        //     {
        //         pts.push_back(min(abs(ope[i] - ope[i + 1]), abs(ope[i] - ope[i + 1])));
        //     }
        // }
        int prev =-1;
        int cur = -1;
        for(int i =0; i <df.size()-1;i++)
        {
            if(stk.empty())
            {
                stk.push(df[i]);
                prev =df[i];
                continue;
            }
            prev =cur;
            cur = stk.top();
            if()
            stk.push(df[i]);
            
        }
    }
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