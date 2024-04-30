#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

int partition(int arr[], int s, int e){
    /*
    int pivot = arr[e];
    int i = s-1;
    for(int j=s; j<e; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
    */
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int pivotIndex = s+cnt;
    swap(arr[s], arr[pivotIndex]);
    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){
// 1st method
        /* 
        if(arr[i]<=pivot){
            i++;
        }else if(arr[j]>pivot){
            j--;
        }else{
        swap(arr[i], arr[j]);
        i++;
        j--;
        } 
        */
// 2nd method
        /*
        int i = s, j = s+1;
        if(pivot > arr[j]){
            i++;
            swap(arr[i], arr[j])
            j++;
        }else{
            j++;
        }
        */
// 3rd method
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}
void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}
int main(){
    int arr[] = {42,84,75,20,60,10,90,50,5,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}