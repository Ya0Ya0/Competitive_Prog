#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        auto query = [&](int x, int y) {
            if (x < 1 || x > n || y < 1 || y > m)
                return -1;
            cout << "? " << x << ' ' << y << endl;
            int z;
            cin >> z;
            return z;
        };
        int tl = query(1, 1);
        int tr = query(1, m);
        int bl = query(n, 1);
        int br = query(n, m);
        if (tl == tr && bl == br) {
            int d = query(n, n);
            if (d == tl) {
                cout << "! 1 1" << endl;
            } else {
                cout << "! " << n << ' ' << n << endl;
            }
        } else if (tl == bl && tr == br) {
            int d = query(1, n);
            if (d == tl) {
                cout << "! 1 " << m << endl;
            } else {
                cout << "! " << n << ' ' << 1 << endl;
            }
        } else {
            int d1 = query(1, n);
            int d2 = query(n, 1);
            if (d1 == tl) {
                cout << "! 1 " << m << endl;
            } else if (d1 == tr) {
                cout << "! 1 1" << endl;
            } else if (d2 == bl) {
                cout << "! " << n << ' ' << 1 << endl;
            } else {
                cout << "! " << n << ' ' << m << endl;
            }
        }
    }
    return 0;
}