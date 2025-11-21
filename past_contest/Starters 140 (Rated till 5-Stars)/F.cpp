#include<string>
#include<vector>
#include<iostream>
using namespace std;
vector<int> z_function(string s)
{
   int n = s.size();
   vector<int> z(n, 0);
   int l = 0, r = 0;
   for (int i = 1; i < n; ++i)
   {
      if (i <= r) 
         z[i] = min(r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
         z[i]++;
      if (i + z[i] - 1 > r)
         l = i, r = i + z[i] - 1;
   }
   return z;
}

string shortestCompressedString(string s) {
    int n = s.length();
    vector<int> z = z_function(s);
  
    // Now using Z function to calculate the shortest compressed string
    string compressedString = "";
    for (int i = 1; i < n; i++) {
        if(!(n%i == 0))
            continue;
        if(i+z[i] == n)
        {
            return s.substr(0,i);
        }
    }
    return s;
}
int main() {
    string s = "aaaaa";
    cout<<shortestCompressedString(s)<<endl;
    return 0;
}  