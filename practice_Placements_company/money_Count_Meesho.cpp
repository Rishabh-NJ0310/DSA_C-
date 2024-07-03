# /*
#     money count
#     given denominators are 20 cents, 40 cents, 1 dollar, 2 dollars, 5 dollars, 10 dollars

#     Given the count of each denoomination (in asecending order from 20 cents to t10 dollars) provide by the customer (0 will be given if the denomination is not present)
#     calculate amount 
#     100 cents = 1 dollar

#     input 
#     the input consists of a single line.
#     6 space separated integers, representing the count of each denomination from 20 cents to 10 dollars

#     output - single value representing the total amount round of to one decimal spcae
    
#     input 1
#     1 1 1 1 1 1 
#     18.6
#     5 5 5 5 5 5
#     93.0
#  */


#include <bits/stdc++.h>
using namespace std;

float money_count(int a, int b, int c, int d, int e, int f) {
    float amount = 0.0;
    amount += a * 0.2;
    amount += b * 0.4;
    amount += c * 1.0;
    amount += d * 2.0;
    amount += e * 5.0;
    amount += f * 10.0;
    // return amount to one decimal place
    return round(amount * 10) / 10;
}

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << fixed << setprecision(1) << money_count(a, b, c, d, e, f) << endl;
    
    return 0;
}
