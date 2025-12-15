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
void init(){};
void Solve()
{
    int n; 
    cin >> n;
    read(ent,n);
    vector<ll>odd,even,even1,odd1;
    // ll sum = accumulate(all(ent),0LL);
    for(int i =0;i < n;i++){
        if(ent[i]&1)odd.push_back(ent[i]);
        else even.push_back(ent[i]);
    }
    
    sort(all(even));
    sort(all(odd));
    if(odd.size()==0){
        for(int i =0;i <n;i++)cout << 0 <<" ";
        cout << "\n";return;
    }
    even1 = even;
    odd1 = odd;
    ll ans =odd.back();
    cout << ans <<" ";
    int i =0;
    multiset<ll>evens,odds;
    odds.insert(odd.back());
    odd.pop_back();
    // cout << *odds.rbegin() <<" ";
    // ans = *odds.rbegin();
    for(int i =1;i < n;i++){
        if(even.size() && odds.size()&1){
            evens.insert(even.back());
            ans+=even.back();
            even.pop_back();            
        }else if(!even.size() && even1.size()&& odd.size()>1){
            even.push_back(*evens.begin());
            ans-=even.back();
            evens.erase(evens.begin());

            odds.insert(odd.back());
            odd.pop_back();
            odds.insert(odd.back());
            odd.pop_back();
        }else if((odds.size()&1)){
            odds.insert(odd.back());
            odd.pop_back();
            cout << 0 <<" ";continue;
        }else{
            odds.insert(odd.back());
            odd.pop_back();
            cout << ans <<" ";continue;
        }
        cout << ans <<" ";
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}