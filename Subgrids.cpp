
#include <iostream>
#include <vector>

using namespace std;

int countSubgrids(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;

    // Prefix sum matrix
    vector<vector<int>> prefix_sum(n + 1, vector<int>(n + 1, 0));

    // Calculate prefix sum
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix_sum[i][j] = grid[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    // Iterate over all possible subgrid sizes
    for (int size = 1; size <= n; ++size) {
        for (int i = size; i <= n; ++i) {
            for (int j = size; j <= n; ++j) {
                // Calculate the sum of the subgrid
                int subgrid_sum = prefix_sum[i][j] - prefix_sum[i - size][j] - prefix_sum[i][j - size] + prefix_sum[i - size][j - size];
                // If the sum equals the subgrid size (all corners black), increment the count
                if (subgrid_sum == size * size) {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the dimension of the grid: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    cout << "Enter the color of each cell (0 for white, 1 for black):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = countSubgrids(grid);
    cout << "Total number of subgrids whose all corners are black: " << result << endl;

    return 0;
}
