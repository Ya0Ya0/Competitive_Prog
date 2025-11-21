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
    map<pair<int, int>, set<pair<int, int>>> mp;
    auto func = [&](int i, int j, auto self)
    {
        bool ok = false;
        if(i == n)return false;
        // if (i > 0 && j == 0)
        // {
        //     for (int k = 0; k <= n; k++)
        //     {
        //         if (cnt[i - 1][k] == 0 || (cnt[i - 1][k] > 40))
        //             continue;
        //         else
        //             return true;
        //     }
        // }
        
        
        // if (i == n)
        // {

        //     for (int k = 0; k <= n; k++)
        //     {
        //         if (cnt[i][k] == 0 || (cnt[i][k] > 40))
        //             continue;
        //         else
        //             return true;
        //     }
        //     // for (int k = 0; k <= n; k++)
        //     // {
        //     //     if (cnt[i-1][k] == 0 || (cnt[i-1][k] > 40))continue;
        //     //     else return true;
        //     // }
        //     return false;
        // }
        for (int k = 0; k < 2; k++)
        {
            ok = false;

            if (k == 0)
            {
                pair<int, int> tl = {i, j}, br = {i + 1, j + 1};
                r[i][j] = '\\';

                cnt[tl.first][tl.second]--;
                cnt[br.first][br.second]--;
                if (cnt[tl.first][tl.second] < 0 || cnt[br.first][br.second] < 0)
                {
                    cnt[tl.first][tl.second]++;
                    cnt[br.first][br.second]++;
                    ok = true;
                    continue;
                }
                for (auto e : mp[{i, j}])
                    mp[{i + 1, j + 1}].insert(e);
                mp[{i + 1, j + 1}].insert({i, j});
                if (j + 1 < n)
                    ok |= self(i, j + 1, self);
                else
                {
                    for (int k = 0; k <= n; k++)
                    {
                        if (cnt[i][k] == 0 || (cnt[i][k] > 40))
                            continue;
                        else
                            return true;
                    }
                    ok |= self(i + 1, 0, self);
                }
                if (!ok)
                    break;
                mp[{i + 1, j + 1}].clear();
                cnt[tl.first][tl.second]++;
                cnt[br.first][br.second]++;
            }
            else if (k)
            {
                pair<int, int> tr = {i, j + 1}, bl = {i + 1, j};

                r[i][j] = '/';
                
                cnt[tr.first][tr.second]--;
                cnt[bl.first][bl.second]--;

                if (cnt[tr.first][tr.second] < 0 || cnt[bl.first][bl.second] < 0)
                {
                    cnt[tr.first][tr.second]++;
                    cnt[bl.first][bl.second]++;

                    ok = true;
                    continue;
                }

                for (auto e : mp[{i, j + 1}])
                    mp[{i + 1, j}].insert(e);
                mp[{i + 1, j}].insert({i, j + 1});

                if (j > 0 && r[i][j - 1] == '\\')
                {
                    // if(r[3]=="/\\//" && r[0]=="\\//\\")
                    //     zz++;
                    int l = mp[{i, j + 1}].size(), rr = mp[{i, j - 1}].size();
                    if (l + rr + 2 != mp[{i + 1, j}].size())
                        ok = true;
                }
                if (ok)
                {
                    mp[{i + 1, j}].clear();
                    cnt[tr.first][tr.second]++;
                    cnt[bl.first][bl.second]++;
                    continue;
                }
                if (j + 1 < n)
                {
                    ok |= self(i, j + 1, self);
                }
                else
                {
                    for (int k = 0; k <= n; k++)
                    {
                        if (cnt[i][k] == 0 || (cnt[i][k] > 40))
                            continue;
                        else
                            return true;
                    }
                    ok |= self(i + 1, 0, self);
                }

                mp[{i + 1, j}].clear();
                cnt[tr.first][tr.second]++;
                cnt[bl.first][bl.second]++;
            }
        }
        if (i == 0 && j == 0 && ok)
            assert(false);
        return ok;
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