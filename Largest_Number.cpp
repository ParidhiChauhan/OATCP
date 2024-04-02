#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        for (const int num : nums)
            ans += to_string(num);

        return ans[0] == '0' ? "0" : ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution solution;
    string result = solution.largestNumber(nums);
    cout << "The largest number formed is: " << result << endl;

    return 0;
}
