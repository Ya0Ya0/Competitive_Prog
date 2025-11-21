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
/*
2 1
00
2 2
00
2 1
10
*/
void Solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> chunck;
    for (int i = 0; i < n; i++)
    {
        int ok = 1;
        for (int j = 0; (j < k - 1 || s[i + j] == s[i + 1 + j]) && j < n; j++)
        {
            if (s[i + j] == s[i + 1 + j])
            {
                ok++;
            }
            else
                break;
        }
        chunck.push_back(ok);
        i += ok - 1;
    }
    int pos = 0;
    ll sum = 0;
    for (int i = 0; i < chunck.size(); i++)
    {
        if (chunck[i] != k)
        {
            sum = 0;
            for (int j = 0; j < i; j++)
                sum += chunck[j];
            if (k - chunck[i] > 0)
            {
                sum += chunck[i];
            }
            else
            {
                sum += chunck[i] - k;
            }
            reverse(s.begin(), s.begin() + sum);
            s = s.substr(sum) + s.substr(0, sum);
            break;
        }
    }

    chunck.clear();
    for (int i = 0; i < n; i++)
    {
        int ok = 1;
        for (int j = 0; (j < k - 1 || s[i + j] == s[i + 1 + j]) && j < n; j++)
        {
            if (s[i + j] == s[i + 1 + j])
            {
                ok++;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
        chunck.push_back(ok);
        i += ok - 1;
    }
    for(auto c : chunck)
    {
        if(c != k)
        {
            cout << -1 <<"\n"; return;
        }
    }
    cout << (sum == 0 ? n : sum) << "\n";
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