#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class Solution {

private:
    void merge(vector<int>& arr, int s, int mid, int e) {
        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> first(len1);
        vector<int> second(len2);

        // Copy elements to first and second arrays
        for (int i = 0; i < len1; ++i) {
            first[i] = arr[s + i];
        }
        for (int i = 0; i < len2; ++i) {
            second[i] = arr[mid + 1 + i];
        }

        int index1 = 0, index2 = 0;
        int mainIndexArray = s;
        
        // Merge the two arrays
        while (index1 < len1 && index2 < len2) {
            if (first[index1] <= second[index2]) {
                arr[mainIndexArray++] = first[index1++];
            } else {
                arr[mainIndexArray++] = second[index2++];
            }
        }

        // Copy remaining elements of first array
        while (index1 < len1) {
            arr[mainIndexArray++] = first[index1++];
        }

        // Copy remaining elements of second array
        while (index2 < len2) {
            arr[mainIndexArray++] = second[index2++];
        }
    }

    void mergeSort(vector<int>& arr, int s, int e) {
        if (s >= e) {
            return;
        }
        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};



int main(){
    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> ans = s.sortArray(nums);
    for(auto i: ans){
        cout<<i<<" ";
    }
return 0;
}