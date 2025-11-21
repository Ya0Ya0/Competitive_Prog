#include <bits/stdc++.h>
using namespace std;
string sum(string num1, string num2)
{
    int len = max(num1.length(),num2.length());
        int carry = 0;
        string ans;
        if(num1=="")
            return num2;
        else if(num2=="")
            return num1;
        for(int i = 0; i <len || carry;i++)
        {
            int a =  num1.length()>i? num1[num1.length()-i-1]-'0':0;
            int b =  num2.length()>i? num2[num2.length()-i-1]-'0':0;
            int mult = a+b+carry;
            carry = mult/10;
            ans.push_back((mult % 10) + '0');
        }
        reverse(ans.begin(),ans.end());
        return ans;

}
string multiply(string num1, string num2) {
        int len = max(num1.length(),num2.length());
        int carry = 0;
        string ans="";
        for(int i = num1.length()-1; i >= 0 ;i--)
        {
            string temp;
            carry = 0;
            for(int j = num2.length()-1; j >=0 || carry; j--)
            {
                int one = j>=0?(num2[j]-'0'):0,two = j>=0?((num1[i])-'0'):1;
                int aux = one*two  +carry;
                int div = 10;                
                temp.push_back(aux%10+'0');
                carry = aux/10;
            }
            reverse(temp.begin(),temp.end());
            for(int z=0;z < num1.length()-1-i; z++)
            {
                temp.push_back('0');
            }
            ans = sum(temp,ans);
        }     
        int k = 0;   
        while(ans[k]=='0' && ans.length()-k>1)k++;        
        return ans.substr(k,ans.length()-k);
}
typedef struct z
{
    int z;
    char k[30];
};
 
void Solve()
{
    char a[] = "hello";
    z j[]={{5,"byebye"},{4,"Monga"},{8,"Yuma"}};

    vector<int> sa{2, 1, 8};
    vector<int> b{4, 5, 6};
    cout << multiply("0","0");
    
    
    
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
    cout << "pinga\n";
}