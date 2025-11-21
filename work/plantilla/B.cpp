#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int n, dis[MAXN][MAXN], cost[MAXN][MAXN];

void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
        cost[a][b] = c;
    }

    floydWarshall();

    long long int minCost = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INT_MAX) {
                minCost += cost[i][j];
            }
        }
    }

    cout << minCost << endl;
    return 0;
}