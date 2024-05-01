#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
template<typename T> // Add typename keyword and specify the template parameter type

class Sorting{
    private:
    vector<T> arr;
    public:
    Sorting(vector<T> arr){
        this->arr = arr;
    }
    void insertionSort(){
        for (int i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void bubbleSort(){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size()-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    void selectionSort(){
        for(int i=0;i<arr.size();i++){
            int minIndex = i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<arr[minIndex]){
                    minIndex = j;
                }
            }
            swap(arr[i],arr[minIndex]);
        }
    }
    void merge(int l,int m,int r){
        int n1 = m-l+1;
        int n2 = r-m;
        vector<T> L(n1),R(n2);
        for(int i=0;i<n1;i++){
            L[i] = arr[l+i];
        }
        for(int i=0;i<n2;i++){
            R[i] = arr[m+1+i];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(int l,int r){
        if(l<r){
            int m = l+(r-l)/2;
            mergeSort(l,m);
            mergeSort(m+1,r);
            merge(l,m,r);
        }
    }
    void quickSort(int low,int high){
        if(low<high){
            int pi = partition(low,high);
            quickSort(low,pi-1);
            quickSort(pi+1,high);
        }
    }
    int partition(int low,int high){
        T pivot = arr[high];
        int i = low-1;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    void heapify(int n,int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n && arr[l]>arr[largest]){
            largest = l;
        }
        if(r<n && arr[r]>arr[largest]){
            largest = r;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(n,largest);
        }
    }
    void heapSort(){
        for(int i=arr.size()/2-1;i>=0;i--){
            heapify(arr.size(),i);
        }
        for(int i=arr.size()-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(i,0);
        }
    }
    void countingSort(){
        T max = *max_element(arr.begin(),arr.end());
        T min = *min_element(arr.begin(),arr.end());
        int range = max-min+1;
        vector<T> count(range),output(arr.size());
        for(int i=0;i<arr.size();i++){
            count[arr[i]-min]++;
        }
        for(int i=1;i<count.size();i++){
            count[i] += count[i-1];
        }
        for(int i=arr.size()-1;i>=0;i--){
            output[count[arr[i]-min]-1] = arr[i];
            count[arr[i]-min]--;
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = output[i];
        }
    }
    void radixSort(){
        T max = *max_element(arr.begin(),arr.end());
        for(int exp=1;max/exp>0;exp*=10){
            countingSort();
        }
    }
    void bucketSort(){
        int n = arr.size();
        vector<T> b[n];
        for(int i=0;i<n;i++){
            int bi = n*arr[i];
            b[bi].push_back(arr[i]);
        }
        for(int i=0;i<n;i++){
            sort(b[i].begin(),b[i].end());
        }
        int index = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<b[i].size();j++){
                arr[index++] = b[i][j];
            }
        }
    }
    void shellSort(){
        for(int gap=arr.size()/2;gap>0;gap/=2){
            for(int i=gap;i<arr.size();i++){
                T temp = arr[i];
                int j;
                for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
                    arr[j] = arr[j-gap];
                }
                arr[j] = temp;
            }
        }
    }
    void cocktailSort(){
        bool swapped = true;
        int start = 0;
        int end = arr.size()-1;
        while(swapped){
            swapped = false;
            for(int i=start;i<end;i++){
                if(arr[i]>arr[i+1]){
                    swap(arr[i],arr[i+1]);
                    swapped = true;
                }
            }
            if(!swapped){
                break;
            }
            swapped = false;
            end--;
            for(int i=end-1;i>=start;i--){
                if(arr[i]>arr[i+1]){
                    swap(arr[i],arr[i+1]);
                    swapped = true;
                }
            }
            start++;
        }
    }
    void print(){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


int main(){

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    Sorting<int> s(arr);
    s.print();

return 0;
}