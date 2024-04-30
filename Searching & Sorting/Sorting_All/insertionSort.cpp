#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

// void insertionSort(int arr[], int s, int e){
//     for(int i=s;i<e;i++){
//         int min = arr[i];
//         int j = i-1;
//         while(j >=0 && arr[j] > min){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = min;
//     }
// }
// using for loop only 

void insertionSort(int arr[], int s, int e){
    for(int i = s;i<e;i++){
        int min = arr[i];
        for(int j = i-1;j>=0;j--){
            if(arr[j] > min){
                arr[j+1] = arr[j];
                arr[j] = min;
            }
        }
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, 0, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}