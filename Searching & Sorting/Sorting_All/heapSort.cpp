#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class heap{
private:
    int *arr = new int[100];
    int size;
    
public:
    heap(){
        arr[0] = -1;
        this->size = 0;
    }
void insert(int n){
    size++;
    int index = size;
    arr[index] = n;

    while(index > 1){
        int parent = index/2;

        if(arr[parent] < arr[index]){
            swap(arr[parent], arr[index]);
            index = parent;
        }else{
            return;
        }
    }
}

void remove(int n){
    int index = 1;
    swap(arr[index], arr[size]);
    size--;
    while(index < size){
        int left = 2*index;
        int right = 2*index + 1;
        if(left < size && arr[index] < arr[left]){
            swap(arr[index], arr[left]);
            index = left;
        }else if(right < size && arr[index] < arr[right]){
            swap(arr[index], arr[right]);
            index = right;
        }else {
            return;
        }
    }
}

void print(){
    for(int i = 1; i <= size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};


void heapify(vector<int> &arr, int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;

    if(left <= size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapSort(vector<int> &arr, int size){
    int t = size;

    while(t > 1){
        swap(arr[t], arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){
    vector<int> arr = { -1 , 12, 11, 13, 5, 6, 7};
    int n = arr.size();

    for(int i = n/2 ; i > 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    for(int i = 1; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}