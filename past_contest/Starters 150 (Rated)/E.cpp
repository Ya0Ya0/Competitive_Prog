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
    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    int sz = 1;
    vector<int> szs(n);
    vector<int> ini(n);
    bool ok = false;
    int pos = -1;
    if (s1 == s2)
    {
        cout << 0 << "\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {

        if (s2[i] == s2[i - 1])
        {
            sz++;
        }

        else
        {
            for (int j = 0; j < sz; j++)
            {
                szs[i - 1 - j] = sz;
                ini[i - 1 - j] = i - 1;
            }
            if (szs[i-1] >= k)
            {
                ok = true;
                pos = ini[i-1];
            }
            sz = 1;
        }
        if (i == n - 1)
        {
            for (int j = 0; j < sz; j++)
            {
                szs[i - j] = sz;

                ini[i - j] = i;
            }
            if (sz >= k)
            {
                ok = true;
                pos = ini[i];
            }
            sz = 1;
        }
    }
    vector<string> ans;
    for (int i = 0; i <= pos - szs[pos]; i++)
    {
        if (s1[i] != s2[i])
        {
            if (!ok)
            {
                cout << -1 << "\n";
                return;
            }

            string kk = to_string(i + 1) + " " + s2[i];
            ans.push_back(kk);
        }
    }
    for (int i = n - 1; i > pos; i--)
    {
        if (s1[i] != s2[i])
        {
            if (!ok)
            {
                cout << -1 << "\n";
                return;
            }

            string kk = to_string(i - k + 2) + " " + s2[i];
            ans.push_back(kk);
        }
    }
    for (int i = pos - szs[pos]+1; i <= pos - k + 1; i++)
    {
        string kk = to_string(i+1) + " " + s2[i];
        ans.push_back(kk);
    }
    cout << ans.size() << "\n";
    for (auto s : ans)
    {
        cout << s << "\n";
    }
}
/*
if (s1[i] != s2[i])
        {
            if (szs[i] < k)
            {
                int r = ini[i] + 1, l = ini[i] - k;
                if ((r < n && szs[r] >= k))
                {
                    int idx = i;
                    string kk = to_string(idx + 1) + " " + s2[i];
                    ans.push_back(kk);
                    for (int j = 0; j < k; j++)
                    {
                        s1[idx + j] = s2[idx + j];
                    }
                }
                else if (l >= 0 && szs[l] >= k)
                {
                    int idx = i-k;
                    string kk = to_string(idx + 1) + " " + s2[i];
                    ans.push_back(kk);
                    string k1 = to_string(idx + 1) + " " + s2[i];
                    ans.push_back(k1);
                    for (int j = 0; j < k; j++)
                    {
                        if(idx+j>=i)
                        s1[idx + j] = s2[idx + j];
                    }
                    string zz = to_string(l -szs[l]) + " " + s2[l];
                    ans.push_back(zz);
                }
                else
                {
                    cout << -1 << "\n";
                    return;
                }
            }
            else
            {
                int idx = min(i, ini[i] - k + 1);
                string kk = to_string(idx + 1) + " " + s2[i];
                ans.push_back(kk);
                for (int j = 0; j < k; j++)
                {
                    s1[idx + j] = s2[idx + j];
                }
            }
        }*/
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
/*
9 3
asdfasdfs
asdfasdfs
1
10 3
aadddeetee
aaaaaeeeee
1
10 3
aaabbdddad
zzaaaaaabb
*/