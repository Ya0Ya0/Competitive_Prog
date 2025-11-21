#include <bits/stdc++.h>
using namespace std;


    string reversePrefix(string word, char ch) {
        auto f = word.find(ch);
        reverse(word.begin(),word.begin()+f+1);
        return word;
        queue<int> q ;
        q.
    }

void Solve()
{
    vector<int> a{2, 1, 8};
    vector<int> b{4, 5, 6};
    cout << reversePrefix("abcdefd",'d');
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}