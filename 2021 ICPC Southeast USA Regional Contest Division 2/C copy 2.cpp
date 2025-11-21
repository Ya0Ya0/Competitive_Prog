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
    // read(ent,n);
    vector<string> mat(n + 1), r(n, string(n, '+'));
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j <= n; j++)
        {
            if (mat[i][j] == '+')
                cnt[i][j] = 50;
            else
                cnt[i][j] = mat[i][j] - '0';
        }
    }
    vector<int> dsu(1000);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dsu[100+10*i+j] =100+10*i+j;
        }
    }
    auto par = [&](int x, auto self) ->  int
    {
        // auto b = 100+10*x.first+x.second;
        auto a = (dsu[x]);
        if (a == x)
            return x;
        return self(dsu[x], self);
    };
    auto func = [&](int i, int j, auto self)
    {
        int x = 100+10*i+j;
        // if(i > 0 && j == 0)
        // {
        //     for (int k = 0; k <= n; k++)
        //     {
        //         if (cnt[i-1][k] != 0 && cnt[i-1][k] < 40)
        //         {
        //             return false;
        //         }
        //     }
        // }
        if(j == 0 && i > 1)
        {
            if (cnt[i-2][n] != 0 && cnt[i-2][n] < 40)
                {
                    return false;
                }
        }
        if (i == n)
        {
            for (int k = 0; k <= n; k++)
            {
                if (cnt[i-1][k] != 0 && cnt[i-1][k] < 40)
                {
                    return false;
                }
            }
            for (int k = 0; k <= n; k++)
            {
                if (cnt[i][k] != 0 && cnt[i][k] < 40)
                {
                    return false;
                }
            }
            return true;
        }
        bool ans = true;
        for (int z = 0; z < 2; z++)
        {
            bool zzz =false;
            // if(dsu[{0,1}]==make_pair(0,3))
            // {
            //     zzz = true;
            // }
            if(i > 0)
            {
                if (cnt[i-1][j] != 0 && cnt[i-1][j] < 40)
                {
                    return false;
                }
            }
            if (!z)
            {
                r[i][j] = '\\';
                if(cnt[i][j] > 1 && cnt[i][j] < 40)return false;
                cnt[i][j]--;
                cnt[i + 1][j + 1]--;
                if (cnt[i][j] < 0 || cnt[i + 1][j + 1] < 0)
                {
                    cnt[i][j]++;
                    cnt[i + 1][j + 1]++;
                    r[i][j] = '+';
                    continue;
                }
                pair<int, int> nxt = (j < n - 1) ? make_pair(i, j + 1) : make_pair(i + 1, 0);
                auto pare = par(100+10*i+j, par);
                auto prev = par(100+10*(i+1)+j+1, par);
                dsu[prev] = pare;
                ans = self(nxt.first, nxt.second, self);
            //     if(dsu[{0,1}]==make_pair(0,3))
            // {
            //     zzz = true;
            // }
                if (ans)
                    return ans;
                cnt[i][j]++;
                cnt[i + 1][j + 1]++;
                r[i][j] = '+';
                dsu[prev] = prev;
            }
            else
            {
                r[i][j] = '/';
                cnt[i][j + 1]--;
                cnt[i + 1][j]--;
                if (cnt[i][j + 1] < 0 || cnt[i + 1][j] < 0)
                {
                    cnt[i][j + 1]++;
                    cnt[i + 1][j]++;
                    r[i][j] = '+';
                    return false;
                }
                bool tri = false;
                int prevtle;
                if (j > 0 && r[i][j - 1] == '\\')
                {
                    prevtle = par(100+10*i+j-1, par);
                    auto ri = par(100+10*i+j+1, par);
                    auto le = par(100+10*i+j-1, par);
                    if (ri == le)
                    {
                        cnt[i][j + 1]++;
                        cnt[i + 1][j]++;
                        r[i][j] = '+';
                        return false;
                    }
                    dsu[le] = ri;
                    tri = true;
                }

                pair<int, int> nxt = (j < n - 1) ? make_pair(i, j + 1) : make_pair(i + 1, 0);
                auto pare = par(100+10*i+j+1, par);
                auto prev = par(100+10*(i+1)+j, par);
                dsu[prev] = pare;

            //     if(dsu[{0,1}]==make_pair(0,3))
            // {
            //     zzz = true;
            // }
                ans = self(nxt.first, nxt.second, self);
                if (ans)
                    return ans;
                cnt[i][j + 1]++;
                cnt[i + 1][j]++;
                r[i][j] = '+';
                if(tri)dsu[prevtle] = prevtle;
                dsu[prev] = prev;
                
            }
        }
        return ans;
    };
    func(0, 0, func);
    for (auto s : r)
        cout << s << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}