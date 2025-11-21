#include "equal.h"
#include <bits/stdc++.h>
using namespace std;
void make_all_equal(int N, int Q_add, int Q_compare)
{
    // your code here!
    int ini = 0, end = 1;
    if (N == 1)
        return;
    vector<int> upd{0};
    while (ini != N - 1)
    {
        while (!compare(ini, end))
        {
            add(upd, 1);
        }
        upd.push_back(end);
        ini++;end++;
    }
}
