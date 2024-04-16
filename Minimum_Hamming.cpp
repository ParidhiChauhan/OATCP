
   #include <iostream>
#include <vector>

using namespace std;

int hammingDistance(int x, int y) {
    // Count the number of differing bits between x and y
    int distance = 0;
    int xor_result = x ^ y;
    while (xor_result) {
        distance += xor_result & 1;
        xor_result >>= 1;
    }
    return distance;
}

int totalHammingDistance(vector<int>& nums) {
    int total_distance = 0;
    int n = nums.size();
    // Iterate over all pairs of integers in nums
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Calculate Hamming distance between nums[i] and nums[j]
            int distance = hammingDistance(nums[i], nums[j]);
            // Add the distance to the total
            total_distance += distance;
        }
    }
    return total_distance;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = totalHammingDistance(nums);
    cout << "Sum of Hamming distances between all pairs of integers: " << result << endl;

    return 0;
}

