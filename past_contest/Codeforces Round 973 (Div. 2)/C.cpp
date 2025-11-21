#include "bits/stdc++.h"
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
string str[4] = {"10", "01", "00", "11"};
void Solve()
{
    auto tr = [&](string t)
    {
        cout << "? " << t << "\n";
        fflush(stdout);
        int ans;
        cin >> ans;
        fflush(stdout);
        return ans;
    };
    int n;
    cin >> n;
    if (n == 1)
    {
        if (tr("1"))
            cout << "! " << 1 << "\n";
        else
        {
            cout << "! " << 0 << "\n";
        }
        return;
    }
    bool ok = false;
    int z = -1;
    while (!ok)
    {
        z++;
        ok = tr(str[z]);
    }
    if (str[z] == "00" || str[z] == "11")
    {
        cout << "! ";
        for (int i = 0; i < n; i++)
        {
            cout << str[z][0];
        }
        cout << "\n";
        return;
    }
    string cur = str[z];
    int r = 1;
    while (cur.size() < n)
    {
        if (r)
        {
            if (tr(cur + '1'))
            {
                cur += '1';
            }
            else if (tr(cur + '0'))
            {
                cur += '0';
            }
            else{
                r= 0;
            }
        }
        else{
            if (tr( "1" + cur ))
            {
                cur = "1" + cur;
            }
            else if (tr("0" + cur))
            {
                cur ="0" + cur;
            }
            else{
                break;
            }
        }
    }
    cout << "! " << cur << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}