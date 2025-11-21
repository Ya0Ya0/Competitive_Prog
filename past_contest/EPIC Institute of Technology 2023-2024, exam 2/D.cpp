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
    string s;
    cin >> s;
    string k = "";
    k+=s[0];
    vector<string> st{k};
    auto ope = [&](auto self, vector<string> st, int i)
    {
        if (i == s.length())
        {
            for(auto str : st)
            {
                if(str[0] == '0' && str.size() > 1)
                {
                    st.clear();
                    return st;
                }
            }
            return st;
        }
        string nw = "";
        nw = st.size()!=0?st.back():""+ s[i];
        swap(st.back(), nw);
        vector<string> a = self(self, st, i + 1);
        swap(st.back(), nw);
        string m = "";
        st.push_back(m + s[i]);
        vector<string> b = self(self, st, i + 1);
        set<string> sa{all(a)},sb{all(b)};
        if(sa.size() < a.size())a.clear();
        if(sb.size() < b.size())b.clear();
        if (sa.size() > sb.size())
        {
            return a;
        }
        else
        {
            return b;
        }
    };
    auto ans = ope(ope,st,1);
    for(auto str : ans)
    {
        cout << str <<(str == ans.back()?"":"-");
    }
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