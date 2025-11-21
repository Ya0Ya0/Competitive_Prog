#include <iostream>
using namespace std;
#include <algorithm>
int main() {

   /* Type your code here. */
    int money;
    cin >> money;
    if(money == 0)
    {
        cout << "No change"; 
    }
    int dollars = money /100;
    money %= 100;
    int quarters = money /25;
    money %= 25;
    int dimes = money /10;
    money %= 10;
    int nickels = money /5;
    money %= 5; 
    int pennies = money;
    if(dollars)
    {
        cout << dollars << " Dollar" << ((dollars > 1)?"s":"") << endl;
    }
    if(quarters)
    {
        cout << quarters << " Quarter" << ((quarters > 1)?"s":"") << endl;
    }
    if(dimes)
    {
        cout << dimes << " Dime" << ((dimes > 1)?"s":"") << endl;
    }
    if(nickels)
    {
        cout << nickels << " Nickel" << ((nickels > 1)?"s":"") << endl;
    }
    if(pennies)
    {
        cout << pennies << " Pennie" << ((pennies > 1)?"s":"") << endl;
    }
   return 0;
}