#include <bits/stdc++.h>
using namespace std;
#define ll long 

ll tsp(vector<vector<ll>> &cost) {
    ll n = cost.size();
    vector<vector<ll>> dp(n, vector<ll>(1 << n, LONG_MAX));
    vector<vector<int>> parent(n, vector<int>(1 << n, -1));

    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 0;
    }

    for (ll mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) == 0) {
                        ll newCost = dp[u][mask] + cost[u][v];
                        if (newCost < dp[v][mask | (1 << v)]) {
                            dp[v][mask | (1 << v)] = newCost;
                            parent[v][mask | (1 << v)] = u;
                        }
                    }
                }
            }
        }
    }

    ll ans = LONG_MAX;
    int lastNode = -1;
    int finalMask = (1 << n) - 1;

    for (int i = 0; i < n; i++) {
        if (dp[i][finalMask] < ans) {
            ans = dp[i][finalMask];
            lastNode = i;
        }
    }

    cout << ans << "\n";

    vector<int> path;
    int curr = lastNode;
    int mask = finalMask;

    while (curr != -1) {
        path.push_back(curr + 1);
        int prev = parent[curr][mask];
        mask ^= (1 << curr);
        curr = prev;
    }

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<ll>> cost(n, vector<ll>(n));
    for (auto &a : cost)
        for (auto &b : a)
            cin >> b;

    tsp(cost);
    return 0;
}