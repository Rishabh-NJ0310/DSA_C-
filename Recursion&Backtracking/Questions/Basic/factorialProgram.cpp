#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;


int factorial(int number){
    if(number == 1 ){
        return 1;
    }
    return number * factorial((number-1));
}


int main(){
    int number;
    cin>>number;
    cout<<factorial(number);
return 0;
}