/*
Ram is going to attend Arjun's birthday. Ram decided that the gift ne to Arjun is an array Art of n non-negative integers.

Ram created that array 1000 years ago, so some elements in that are Ram knows that Arjun hates to see an array that has two odjacent se high absolute difference between them. He doesn't have much time s choose an integer k (0s k ≤ 109) and replace all missing elements in array Arr with k.

Let m be the maximum absolute difference between all adjacent eleme maximum value of la-0+1 for all 1≤ i ≤ n-1) in the array Arr after Ros missing elements with k.

Ram should choose an integer k so that mis minimized. Print the volu

Input Format -

The first line contains a single integer n-length of the array.

The second line contains n integers Arr₁, Arr2..... Arr, an array, If A the ith integer is missing. It is guaranteed that at least one integer is me test case.

Output Format-

Print the value of m for each given test case in a single line.

Constraints

1 <= n <= 105
Examples

• Input:

5
-1 10 -1 12 -1

Output:

1

Explanation:

In the given test case after replaang all missing elements with 11 the array becomes [11,10,11,12,11]. 
The absolute difference between any adjacent elements is 1. It is impossible to choose a value of k, 
such that the absolute difference between any adjacent element will be ≤ 0. 
So, the answer is 1.
*/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findOptimalK(const vector<int>& arr, int n) {
    int min_val = INT_MAX, max_val = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            if (i > 0 && arr[i - 1] == -1) {
                min_val = min(min_val, arr[i]);
                max_val = max(max_val, arr[i]);
            }
            if (i < n - 1 && arr[i + 1] == -1) {
                min_val = min(min_val, arr[i]);
                max_val = max(max_val, arr[i]);
            }
        }
    }

    if (min_val == INT_MAX) min_val = 0;
    if (max_val == INT_MIN) max_val = 0;

    int k = (min_val + max_val) / 2;

    int max_diff = 0;
    for (int i = 0; i < n - 1; i++) {
        int left = (arr[i] == -1) ? k : arr[i];
        int right = (arr[i + 1] == -1) ? k : arr[i + 1];
        max_diff = max(max_diff, abs(left - right));
    }

    return {k, max_diff};
}

string solve(vector<int> arr, int n) {
    pair<int, int> result = findOptimalK(arr, n);
    return to_string(result.second); 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}
