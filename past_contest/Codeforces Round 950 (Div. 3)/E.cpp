#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vi read_ints(int n) {
    vi res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }
    return res;
}
 
vvi read_matrix(int n, int m) {
    vvi res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = read_ints(m);
    }
    return res;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vvi a = read_matrix(n, m), b = read_matrix(n, m);
    int nm = n * m;
    vi pos1i(nm), pos2i(nm), pos1j(nm), pos2j(nm);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = a[i][j] - 1;
            int y = b[i][j] - 1;
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    }
    vector<set<int>> pi(nm), pj(nm);
    for (int x = 0; x < nm; ++x) {
        int i1 = pos1i[x], i2 = pos2i[x];
        int j1 = pos1j[x], j2 = pos2j[x];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }
    for (int x = 0; x < nm; ++x) {
        if (pi[x].size() > 1 || pj[x].size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}