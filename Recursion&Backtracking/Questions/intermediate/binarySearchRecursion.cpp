#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
int binarySearch(int s, int e, vector<int> arr, int key){
    if(s>e){
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return mid;
    }else if(arr[mid] > key){
        return binarySearch(s, mid-1, arr, key);
    }else{
        return binarySearch(mid+1, e, arr , key);
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int key = 10;
    cout<<binarySearch(0, arr.size()-1, arr, key);
return 0;
}