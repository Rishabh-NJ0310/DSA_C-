#include <iostream>
#include <vector>

std::vector<int> findBalancedPermutation(int N) {
    std::vector<int> result;
    int left = 1, right = N;
    
    while (left < right) {
        result.push_back(left);
        result.push_back(right);
        left++;
        right--;
    }
    
    if (left == right) {  // Odd number of elements, middle element unpaired
        result.push_back(left);
    }
    
    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> result = findBalancedPermutation(N);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
