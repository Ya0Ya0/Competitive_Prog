#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int countValidInversions(const string& s) {
    int n = s.size();
    vector<int> balance(n + 1, 0);
    unordered_map<int, int> balanceCount;
    balanceCount[0] = 1;
    int currentBalance = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        currentBalance += (s[i] == '(') ? 1 : -1;
        balance[i + 1] = currentBalance;

        if (balanceCount.find(currentBalance) != balanceCount.end()) {
            count += balanceCount[currentBalance];
        }
        
        balanceCount[currentBalance]++;
    }

    return count;
}

void solve() {
    int t;
    cin >> t;
    vector<string> testCases(t);
    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
    }

    for (const string& s : testCases) {
        cout << countValidInversions(s) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}