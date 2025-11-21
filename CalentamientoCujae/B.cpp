#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    stack<long long> stk;
    string sss,z;
    long long cur=0;
    
   // getline(cin,ss);
    char c = 'a';
    vector<string>e;
    getline(cin,sss);
        stringstream ss(sss);

    while(ss >> z)
        e.push_back(z);
    for(auto s : e)
    {        
        if (s == "+")
        {
            long long a = stk.top();
            stk.pop();
            long long b = stk.top();
            stk.pop();

            cur = (a + b);
            stk.push(cur);
        }
        else if (s == "-")
        {
            long long a = stk.top();
            stk.pop();
            long long b = stk.top();
            stk.pop();
            cur = (b - a);
                        stk.push(cur);

        }
        else if (s == "*")
        {
            long long a = stk.top();
            stk.pop();
            long long b = stk.top();
            stk.pop();
            cur = (a * b);
                        stk.push(cur);

        }
        else if (s == "/")
        {
            long long a = stk.top();
            stk.pop();
            long long b = stk.top();
            stk.pop();
            cur = (b / a);
                        stk.push(cur);

        }
        else
        {
            stk.push(stoi(s));
        }
    }
    //if(cur!=0)stk.push((cur));
    if(!stk.empty())
        cout << stk.top();
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}