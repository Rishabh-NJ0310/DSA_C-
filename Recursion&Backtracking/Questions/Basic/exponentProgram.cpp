#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

int power(int base,int exponent){
    if(exponent <= 1){
        return base;
    }
    exponent -= 1;
    return base * power(base, exponent);
}

int main(){
    cout<<"Enter the base and Exponent"<<endl;
    int base,exponent;
    cin>>base>>exponent;
    cout<<power(base,exponent);
return 0;
}