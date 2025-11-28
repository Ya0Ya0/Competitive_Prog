#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pq priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define all(x) x.begin(), x.end()

#define read(name, cnt) vector<ll>name(cnt);for(auto &e : name)cin >> e;
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
vector<pair<int,int>> Solve2(int nn, vector<string>&mm)
{
    int n; 
    // cin >> n;
    n = nn;
    vector<pair<int,int>>ope;
    // cout << n <<"\n";
    for(int i =0;i < n;i++)
    {
        string s;//cin >> s;
        s = mm[i];
        for(int j =0;j <n;j++)
        {
            if(s[j] == 'H')
            {
                ope.push_back({i,j});
                break;
            }
        }
        if(ope.size() < i+1)
        {
            ope.clear();
            for(int j =0;j < n;j++)
            {
                ope.push_back({i+1,j+1});
                // cout << i+1 << " " << j+1 <<"\n";
            }
            return ope;
        }
    }
    return ope;
    for(auto [a,b] : ope)cout << a+1 <<" " <<b+1 << "\n";
    
}
bool tests(){
    ll n = (rand() ) % 1000 + 1;
    vector<string>mat(n,string(n,'V'));
    for(auto &s : mat)for(auto &e : s)if(rand()%2)e = 'H';
    auto z = Solve2(n,mat);
    bool ok = true;
    char c = mat[z[0].first][z[0].second];
    for(auto [a,b] : z) if(mat[a][b]!=c)ok = false;
    vector<bool>k(n);
    for(auto [a,b] : z)
    {
        if(c == 'H')k[a] = 1;
        else k[b] = 1;
    }
    for(auto a : k)ok &= a;
    if(!ok )
    {
        cout << n <<"\n";
        for(auto s : mat) cout  << s << "\n";
        return false;
    } return true;
}

void Solve()
{
    int n; 
    cin >> n;
    vector<pair<int,int>>ope,ope2;
    cout << n <<"\n";
    vector<string>mat(n);
    for(auto &s : mat)cin >> s;
    for(int i =0;i < n;i++)
    {
        string s = mat[i];
        for(int j =0;j <n;j++)
        {
            if(s[j] == 'H')
            {
                ope.push_back({i,j});
                break;
            }
        }        
    }
    for(int i =0;i < n;i++)
    {        
        for(int j =0;j <n;j++)
        {
            if(mat[j][i] == 'V')
            {
                ope2.push_back({j,i});
                break;
            }
        }        
    }
    if(ope2.size() > ope.size())ope = ope2;
    for(auto [a,b] : ope)cout << a+1 <<" " <<b+1 << "\n";
    
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tests())
    {
        ;
    }
}