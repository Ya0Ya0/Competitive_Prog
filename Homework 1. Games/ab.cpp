#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 101;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // dp[i][j] will hold the Grundy number for position (i, j)
    int dp[MAX][MAX] = {0};

    // Base: position (0,0) is terminal so its Grundy value is 0.
    dp[0][0] = 0;

    // Compute Grundy values for each cell in increasing order.
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            // Skip (0,0) as it's already set.
            if(i == 0 && j == 0) continue;
            // Use a set to store reachable Grundy numbers
            set<int> reachable;
            // Move up: (i - u, j)
            for (int u = 1; u <= i; u++){
                reachable.insert(dp[i-u][j]);
            }
            // Move left: (i, j - u)
            for (int u = 1; u <= j; u++){
                reachable.insert(dp[i][j-u]);
            }
            // Move diagonally: (i - u, j - u)
            for (int u = 1; u <= min(i, j); u++){
                reachable.insert(dp[i-u][j-u]);
            }
            // Find the minimum excluded value (mex)
            int g = 0;
            while (reachable.count(g)) {
                g++;
            }
            dp[i][j] = g;
        }
    }

    int N;
    cin >> N;
    int nimSum = 0;
    for (int i = 0; i < N; i++){
        int l, c;
        cin >> l >> c;
        nimSum ^= dp[l][c];
    }
    for(int i =0;i < 20;i++)
    {
        for(int j =0;j < 20; j++)
        {
            cout << dp[i][j] <<" ";
        }
        cout << "\n";
    }
    cout << (nimSum != 0 ? "Y" : "N") << "\n";
    return 0;
}