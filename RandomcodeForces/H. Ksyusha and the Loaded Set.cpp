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
#define MAXN 100005
int t[4 * MAXN];
void build(vector<pair<ll, ll>> &a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl].first;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
ll mxx(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return max(mxx(v * 2, tl, tm, l, min(r, tm)), mxx(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
ll c = 5001;
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> player(2, vector<pair<int, int>>(11));
    map<pair<int, int>, string> goal;
    pair<int,int> Q = {(n+1)/2, (m+1)/2};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            if (s == ".." || s == ".Q")
                continue;
            if (s == "RG" || s == "BG")
            {
                goal[{j,i}] = s;
            }
            else{
                int t = s[0] == 'R'? 0 : 1;
                int np = s[1] - '0';
                player[t][np] = {j,i};
            }
        }
    }
    int l;
    cin >> l;
    auto mv = [](string s)-> pair<int,int>{
        if(s == "L")
        {
            return {-1,0};
        }
        if(s == "R")
        {
            return {1,0};
        }
        if(s == "U")
        {
            return {0,-1};
        }
        if(s == "D")
        {
            return {0,1};
        }
        return{0,0};
    };
    /*6 BLUE GOAL
    12 RED GOAL*/
    int redc=0,bluec=0;
    for(int i = 0; i <l; i++)
    {
        string id;cin >> id;
        string op;cin >> op;
        if(op == "C")
        {
            string b;cin >> b;
            continue;
        }
        int t = id[0] == 'R'? 0 : 1;
        int np = id[1] - '0';
        if(op == "T")
        {            
            auto [x,y] = player[t][np];
            if(goal.count({x,y}))
            {
                int tg = goal[{x,y}][0] == 'R'?0 : 1;
                if(tg != t)
                {
                    cout << i << " " << (t == 0?"RED" : "BLUE") << " GOAL\n"; 
                    if(t == 0)redc++;
                    else bluec++;
                }
                else{
                    cout << i << " " << (t == 0?"BLUE" : "RED") << " GOAL\n"; 
                    if(t == 0)bluec++;
                    else redc++;
                }
            }
            else{
                Q = {x,y};
            }
            continue;
        }
        auto [mx,my] = mv(op);
        auto &[x,y] = player[t][np];
        x+=mx;
        y+=my;

    }
    cout << "FINAL SCORE: " << redc << " " << bluec <<"\n";
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