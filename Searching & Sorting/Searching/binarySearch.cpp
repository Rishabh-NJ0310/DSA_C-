#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

bool isPresent(int *arr, int key){
    int size = sizeof(*arr/sizeof(arr[0]));
    
    if(Binary_Search(arr,key) != -1){
        return true;
    }
    return false;
}



int Binary_Search(int *arr, int key){
    int s = 0, e = sizeof(*arr/sizeof(arr[0]))-1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
return -1;
}



int main(){

    int *arr = new int[5];
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<Binary_Search(arr,key)<<endl;
    cout<<isPresent(arr,key)<<endl;
    delete [] arr;
return 0;
}