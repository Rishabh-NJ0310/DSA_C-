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
        if(left > size &&  arr[index] < arr[left]){
            swap(arr[index], arr[left]);
            index = left;
        }else if(right > size && arr[index] < arr[right]){
            swap(arr[index], arr[right]);
            index = right;
        }else{
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
void heapify(int arr[], int n, int index){

    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}


int main(){
    heap h;
    // h.insert(30);
    // h.insert(10);
    // h.insert(20);
    // h.insert(40);
    // h.print();
    int arr[] = {-1,50,51,55,52,56,54,53}; 

    /*
                        50
                    /       \
                   51       55
                  /  \     /  \
                52   56   54  53
                        
    */

    int n = sizeof(arr)/sizeof(arr[0]) - 1;
    for(int i = n/2; i>0; i--){
        heapify(arr,n,i);
    }
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}