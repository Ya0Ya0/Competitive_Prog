#include <bits/stdc++.h>
using namespace std;

int minHeight(int a, int b, int c)
{
    if (a + 1 != c)
    {
        // cout << -1 << "\n";
        return -1;
    }

    int h = 0;
    long long z = 1;
    int lst_layer = 1;
    if (!a)
    {
        // cout << b << "\n";
        return b;
    }
    while (a >= z)
    {
        h++;
        a -= z;
        z <<= 1;
    }
    for(int i =0;i <h;i++)
        lst_layer*=2;
    // extra hight
    if (a)

        // making everything same hight with one clidrens(b)
        if (a)
            h++;
    {
        int ax = min(b, lst_layer - a);
        b -= ax;
        lst_layer += a;
    }
    h += (b + lst_layer - 1) / lst_layer;
    return h;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int h = minHeight(a, b, c);
    if (h == -1)
    {
        cout << "No such tree exists";
    }
    else
    {
        cout << "The minimum height of the tree is: " << h;
    }
    return 0;
}