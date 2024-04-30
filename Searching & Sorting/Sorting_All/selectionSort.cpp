#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

void selectionSort(int arr[], int s, int e){
    for(int i = s;i<e;i++){
        int min = i;
        for(int j = i+1;j<e;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i)swap(arr[min], arr[i]);
    
    }
}
int main(){
    int arr[] = {5, 4, 3, 2, 1};
    selectionSort(arr, 0, 5);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}