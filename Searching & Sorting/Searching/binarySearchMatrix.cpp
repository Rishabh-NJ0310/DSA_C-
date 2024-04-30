#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

int BinarySearchMatrix(int arr[][4], int n, int m, int x){
    int low = 0, high = n*m-1;
    while(low <= high){
        int mid = (low+high)/2;
        /*
        int row = mid/m;
        int column = mid%m;
        */
        if(arr[mid/m][mid%m] == x){ // mid/m is row and mid%m is column
            return mid;
        }
        else if(arr[mid/m][mid%m] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

void printMatrix(int mat[][4], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[][4] = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(arr[0])/sizeof(arr[0][0]);
    printMatrix(arr, n, m);
    cout<<BinarySearchMatrix(arr, n, m, 10);
return 0;
}