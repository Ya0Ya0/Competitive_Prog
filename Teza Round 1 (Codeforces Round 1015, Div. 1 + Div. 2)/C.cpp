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
void Solve()
{
    int n; 
    cin >> n;
    read(a,n);
    read(b,n);
    map<ll,ll>mp;
    ll eq = 0;
    for(int i =0;i < n;i++)
    {
        a[i]--;b[i]--;
    }
    for(int i =0;i < n;i++)
    {
        if(mp[a[i]]==0)
        {
            mp[a[i]] = b[i];
            mp[b[i]] = a[i];
        }
        else if(mp[a[i]] != b[i])
        {
            cout << -1 <<"\n";return;
        }
        if(mp[a[i]] == a[i])
        {
            eq++;
        }
    }
    if(eq>1 || (eq==1 && !(n&1)) || ((n&1) && eq!=1))
    {
        cout << -1 <<"\n";return;
    }
    map<ll,ll>pos,num;
    for(int i =0;i <n;i++)
    {
        pos[a[i]] = i;
        num[i] = a[i];
    }
    
    // cout << n<<"\n";
    vector<ll>dn(n);

    vector<pair<ll,ll>>ope;
    for(int i =1;i <=n;i++)
    {
        if(mp[i] == i)
        {
            if(pos[i]+1!=(n+1)/2 )
                ope.push_back({pos[i]+1,(n+1)/2});
                
            swap(a[pos[mp[i]]],a[n/2]);
            swap(pos[num[(n)/2]],pos[i]);
            swap(num[(n)/2],num[pos[num[n/2]]]);
            dn[n/2]++;
            break;
        }
        // if(i ==n && (n&1))
        //     cout << n-1<<"\n";
    }
    
    for(int i =0,j =0;i <n;i++)
    {
        if(dn[i])continue;
        ll k = a[i];
        if(pos[k]+1!=j+1)
            ope.push_back({pos[k]+1,j+1});
        
        swap(pos[num[j]],pos[k]);
        swap(num[j],num[pos[num[j]]]);
        dn[i]++;

        if(pos[mp[a[i]]] +1 != n-j)
            ope.push_back({pos[mp[a[i]]] +1 , n-j});
        k=mp[a[i]];
        swap(pos[num[n-j]],pos[k]);
        swap(num[n-j],num[pos[num[n-j]]]);
        dn[pos[mp[a[i]]]]++;
        j++;
    }
    cout << ope.size() <<"\n";
    for(auto [a,b] : ope)
    {
        cout << a <<" "<<b <<"\n";
    }
    
    
    // cout << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        Solve();
    }
}