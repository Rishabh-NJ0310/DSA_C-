#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
void merge(int arr[], int s,int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = 0;
    for(int i = 0;i<len1;i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for(int i = 0;i<len2;i++){
        second[i] = arr[mainArrayIndex++];
    }
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
    }else{
        arr[mainArrayIndex++] = second[index2++];
    }
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }
    }
    delete []first;
    delete []second;
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    mergeSort(arr, s, s+(e-s)/2);
    mergeSort(arr, s + (e-s)/2+1, e);
    
    merge(arr, s, e);
}


int main(){
    int arr[] = {5,4,3,2,1};
    mergeSort(arr, 0, 4);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    
return 0;
}