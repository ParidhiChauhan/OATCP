/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, pairs(0);
    cout << "Enter the size of array a: ";
    cin >> n;
    int a[n];

    cout << "Enter the elements of array a:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the size of array b: ";
    cin >> m;
    int b[m];

    cout << "Enter the elements of array b:" << endl;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (abs(a[i] - b[j]) < 2)
            {
                b[j] = 1000;
                pairs++;
                break;
            }

    cout << "Number of pairs with a difference of less than 2: " << pairs << endl;
    return 0;
}
