#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;


int sumOfnumbers(int num, int counter, int sum){
    if(counter == 10){
        return sum;
    }
        cout<<"Enter the number "<< endl;
        cin>>num;
        sum += num;
    return sumOfnumbers(0,counter+1,sum);
}

int main(){
    int ans = sumOfnumbers(0,1,0);
    cout<<"average of the entered number is "<<ans/10<<endl;
return 0;
}