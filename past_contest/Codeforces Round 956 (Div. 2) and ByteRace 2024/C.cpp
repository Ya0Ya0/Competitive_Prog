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
    ll n;
    cin >> n;
    vector<vector<ll>> a(3,vector<ll>(n));
    ll tot = 0;
    for(auto &az : a[0])
    {
        cin >> az;
        tot+=az;
    }
    for(auto &az : a[1])
    {
        cin >> az;
    }
    for(auto &az : a[2])
    {
        cin >> az;
    }
    vector<pair<ll,ll>>ans;
    auto func = [&]()
    {
        vector<pair<ll,ll>>ans;
        ll cur = 0;
        for(int i = 0; i < 3; i++)
        {
            ll temp = 0;
            int j =cur ;
            for(;j < n; j++)
            {
                temp+=a[i][j];
                if(temp>=((tot+2)/3))
                {
                    ans.push_back({cur+1,j+1});
                    temp = 0;
                    break;
                }
                
            }
            cur = j+1;
        }
        if(ans.size() == 3)  
            ans[2].second = n;
        return ans;
    };
    for(int i = 0; i < 3; i++)
    {
        swap(a[0],a[i]);
        for(int i = 1; i < 3; i++)
        {
            swap(a[1],a[i]);
            ans = func();            
            swap(a[1],a[i]);
            if(ans.size() == 3){
                swap(ans[1],ans[i]);
                break;    
            }

        }
        swap(a[0],a[i]);
        if(ans.size() == 3)
            swap(ans[0],ans[i]);
        if(ans.size() == 3)
        {
            for(int i = 0; i < ans.size(); i++)
            {
                cout << ans[i].first <<" "<< ans[i].second << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << -1 <<"\n";
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