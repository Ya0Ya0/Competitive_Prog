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
        int n;cin >> n;
        vector<ll>w(n),ini(n);
        for(auto &e : ini)cin >> e;
        bool ok = false;
        w[0] = ini[0];
        if(ini[0]==0)ok = true;
        for(int i = 1; i < n ;i++)
        {
            if(ini[i] == 0)ok = true;
            w[i] =ini[i] + w[i-1];
        }
        if(!ok){
            cout << 0 <<"\n" ;return;
        }
        ll t = (w[n-1])/2;
        // auto z = lower_bound(all(w),t);
        // if(*z!=t)
        //     z = lower_bound(all(w),t+1),t++;
        // if(*z!=t){
        //     cout << 0 <<"\n";return;
        // }
        ll ans = 0;
        for(ll i = 0; i < n; i++ )
        {
            if((w[i] == t && ini[i] == 0) || ((w[n-1] & 1) && w[i] == t+1 && ini[i] == 0))ans++;
        }
        if(!(w[n-1] & 1))ans *= 2;
        cout << ans <<"\n";
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