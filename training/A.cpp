#include <bits/stdc++.h>
using namespace std;
 
using pii = pair<int, int>;
using ll = long long;
 
int q;
 
const int N = 100;
int n, a[N], L[N], R[N], dp[N];
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    cin >> q;
 
    while (q--) {
        vector <int> vec;
 
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i], vec.push_back(a[i]);
 
        sort(vec.begin(), vec.end());
        vec.resize( unique(vec.begin(), vec.end()) - vec.begin() );
 
        for (int i = 0; i < vec.size(); i++) L[i] = R[i] = -1;
 
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
            if (L[a[i]] == -1) L[a[i]] = i;
            R[a[i]] = i;
        }
 
        int ans = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (i && R[i - 1] < L[i])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 1;
 
            ans = max(ans, dp[i]);
        }
 
        cout << vec.size() - ans << '\n';
    }
}