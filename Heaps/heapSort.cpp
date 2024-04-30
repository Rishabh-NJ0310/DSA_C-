#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

// 1 based indexing code

void build_maxHeap(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        build_maxHeap(arr, n, largest);
    }
}

void build_minHeap(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        build_minHeap(arr, n, smallest);
    }
}

void heapSort(vector<int> &arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        build_maxHeap(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        build_maxHeap(arr, i, 0);
    }
}

void reverseHeapSort(vector<int> &arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        build_minHeap(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        build_minHeap(arr, i, 0);
    }
}
int main(){

    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    heapSort(arr, n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverseHeapSort(arr, n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}