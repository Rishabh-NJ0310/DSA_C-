/*

MEX number of a non-negative set of numbers is the smallest non-negative integer that is not present in the set.
for example, MEX of {0,1,3,4} is 2, MEX of {2,3,4} is 0.

your task is to take a given array A of lenght I and remove the minimum number of elements from it 
so that the MEX of the remaining array is not equal to the MEX value of the original array.
your code should return the minimum number of elements that need to be removed from the array.

if the task is not possible then your code should return -2.

what is the full form of 
MEX -> Minimum EXcluded number
*/

/*
4
0 1 1 4
output: 1

3
2 4 11
output: -2

*/



#include<bits/stdc++.h> 
using namespace std;

vector<int> buildArray(int n){
    vector<int> arr;
    for(int i=0; i<n; i++){
        int j;
        cin>>j;
        arr.push_back(j);
    }

    return arr;
}

int countMex(vector<int> arr, int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    auto it = next(s.begin(),0);
    int match = *it;
    s.erase(it);
    int mex;
    for(int i=0;i<n;i++){

    }
}

int main(){

    int size;
    cin>>size;
    vector<int> arr = buildArray(size);
    sort(arr.begin(), arr.end());
    cout<<countMex(arr, size);
}