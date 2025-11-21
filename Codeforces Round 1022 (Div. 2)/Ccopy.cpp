#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int tc;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        vector<pair<int, int>> order;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            order.push_back({a[i], i});
        }
        sort(order.begin(), order.end(), greater<pair<int, int>>());
        int cnt = 0;
        vector<int> used(n + 1, 0);
        for(int i = 0; i < n; i++){
            auto [val, pos] = order[i];
            if(used[pos]){
                continue;
            }
            cnt++;
            used[pos] = 1;
            int auxval = val, auxpos = pos - 1;
            while(auxpos > 0 && a[auxpos] <= auxval){
                auxval = a[auxpos];
                used[auxpos--] = 1;
            }
            auxval = val, auxpos = pos + 1;
            while(auxpos <= n && a[auxpos] <= auxval){
                auxval = a[auxpos];
                used[auxpos++] = 1;
            }
        }
        cout << cnt << "\n";
    }
}
