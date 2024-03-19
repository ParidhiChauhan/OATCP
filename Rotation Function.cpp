#include <iostream>
#include <vector>
#include <numeric> // for accumulate function
#include <algorithm> // for max function
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        int f = 0;

        // Calculate F(0) first.
        for (int i = 0; i < nums.size(); ++i)
            f += i * nums[i];

        int ans = f;

        for (int i = nums.size() - 1; i > 0; --i) {
            f += sum - nums.size() * nums[i];
            ans = max(ans, f);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxRotateFunc = solution.maxRotateFunction(nums);
    cout << "Maximum Rotate Function: " << maxRotateFunc << endl;

    return 0;
}
