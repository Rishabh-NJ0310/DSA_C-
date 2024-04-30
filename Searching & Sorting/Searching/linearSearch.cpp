#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

bool isPresent(int *arr, int key){
    int size = sizeof(*arr/sizeof(arr[0]));

    if(linear_Search(arr,key) != -1){
        return true;
    }
    return false;
}


int linear_Search(int *arr, int key){
    int size = sizeof(*arr/sizeof(arr[0]));
    for(int i = 0;i<size;i++){
        if(arr[i] == key){
            return i;
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
    cout<<linear_Search(arr,key)<<endl;
    cout<<isPresent(arr,key)<<endl;
    delete[] arr;
return 0;
}