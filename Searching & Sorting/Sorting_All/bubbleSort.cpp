#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

void bubbleSort(int arr[], int s, int e){
    for(int i=0;i<e;i++){
        bool flag = false;
        for(int j = i+1;j<e;j++) {
            if(arr[j]<arr[i]){
                swap(arr[j], arr[i]);
                flag = true;
            }
    }
    if(flag == false){
        break;
    }
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, 0, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}