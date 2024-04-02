/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        for (int i = 0; i < costs.size(); ++i)
            if (coins >= costs[i])
                coins -= costs[i];
            else
                return i;

        return costs.size();
    }
};

int main() {
    Solution solution;
    vector<int> costs;
    int coins, n, cost;

    cout << "Enter the number of ice cream costs: ";
    cin >> n;

    cout << "Enter the ice cream costs: ";
    for (int i = 0; i < n; ++i) {
        cin >> cost;
        costs.push_back(cost);
    }

    cout << "Enter the number of coins you have: ";
    cin >> coins;

    int maxIceCreamCount = solution.maxIceCream(costs, coins);
    cout << "You can buy a maximum of " << maxIceCreamCount << " ice creams." << endl;

    return 0;
}
