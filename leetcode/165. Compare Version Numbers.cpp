#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{
    while (version1.length() > 0 || version2.length() > 0)
    {
        int num1 = version1.length() > 0?stoi(version1.substr(0, version1.find('.'))) : 0,
         num2 = version2.length() > 0?stoi(version2.substr(0, version2.find('.'))):0;
        if (num1 > num2)
            return 1;
        if (num2 > num1)
            return -1;
        if (version1.find('.')!=-1)
            version1 = version1.substr(version1.find('.') + 1, version1.length() - version1.find('.') - 1);
        else
            version1 = "";
        if (version2.find('.')!=-1)
            version2 = version2.substr(version2.find('.') + 1, version2.length() - version2.find('.') - 1);
        else
            version2 = "";
    }
    return 0;
}
void Solve()
{
    vector<int> a{2, 1, 8};
    vector<int> b{4, 5, 6};
    compareVersion("123.123", "123.123.123.123");
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}