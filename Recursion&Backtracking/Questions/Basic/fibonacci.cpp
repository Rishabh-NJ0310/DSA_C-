#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

int fibonacciSeries_pinglaSutra(int number){
    if(number <= 1 || number == 0){
        cout<<"                 Returning number "<< number << endl;
        return number;
    }
    cout<<"current number "<< number <<endl;
    return fibonacciSeries_pinglaSutra(number-1) + fibonacciSeries_pinglaSutra(number-2);
}


int main(){
    int number;
    cin>>number;
    cout<<fibonacciSeries_pinglaSutra(number);
return 0;
}