#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

void shellSort(int arr[], int s, int e){
    for(int gap = e/2; gap>0; gap/=2){
        for(int i = gap; i<e; i++){
            int temp = arr[i];
            int j;
            for(j = i; j>=gap && arr[j-gap]>temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}



int main(){

    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    shellSort(arr, 0, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}