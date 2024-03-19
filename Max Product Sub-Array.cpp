#include <iostream>
using namespace std;

/* Returns the product of max product subarray.*/
int maxSubarrayProduct(int arr[], int n)
{
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        // traversing in current subarray
        for (int j = i + 1; j < n; j++)
        {
            // updating result every time
            // to keep an eye over the maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        // updating the result for (n-1)th index.
        result = max(result, mul);
    }
    return result;
}

// Driver code
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum Subarray product is " << maxSubarrayProduct(arr, n);
    return 0;
}

