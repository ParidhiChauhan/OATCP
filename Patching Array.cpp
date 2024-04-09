/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int minPatches(vector<int>& nums, int n) {
    long miss = 1, added = 0, i = 0;

    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            ++added;
            miss += miss;
        }
    }
    return added;
}

int main() {
    string line1, line2;

    cout << "Enter the elements of the array separated by spaces: ";
    getline(cin, line1);

    cout << "Enter the target number: ";
    getline(cin, line2);

    vector<int> nums;
    stringstream ss(line1);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    int target = stoi(line2);

    int patches = minPatches(nums, target);
    cout << "Minimum patches required: " << patches << endl;

    return 0;
}
