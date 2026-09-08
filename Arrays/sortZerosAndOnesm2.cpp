// 2 - pointer method
#include <iostream>
using namespace std;
class Solution
{
    public:
        void segregate0and1(int arr[], int n)
        {
            int l = 0;
            int h = n - 1;
            while (l < h)
            {
                if (arr[l] == 1 && arr[h] == 0)
                {
                    swap(arr[l], arr[h]);
                    l++;
                    h--;
                }
                else
                {
                    if (arr[l] == 0)
                        l++;
                    if (arr[h] == 1)
                        h--;
                }
            }
        }

};
int main()
{
    int arr[] = {0,1,1,0,0,1,1,0,1};
    int n = 9; //int n = sizeof(arr) / sizeof(arr[0]);

    Solution s1;
    s1.segregate0and1(arr, n);
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

// In C++, the line int n = sizeof(arr) / sizeof(arr[0]); is used to calculate the number of elements in an array. Here's how it works:

// 1. sizeof(arr):
// sizeof is an operator that returns the size of a variable or data type in bytes.
// arr is an array of integers, so sizeof(arr) gives you the total size in bytes of the entire array.
// 2. sizeof(arr[0]):
// arr[0] refers to the first element in the array, which is of type int.
// sizeof(arr[0]) gives you the size in bytes of a single integer (int).
// 3. Dividing the Sizes:
// When you divide sizeof(arr) by sizeof(arr[0]), you're dividing the total size of the array by the size of one element.
// This gives you the number of elements in the array.
// Example:
// Let's say you have an array of 9 integers:

// cpp
// Copy code
// int arr[] = {0, 1, 1, 0, 0, 1, 1, 0, 1};
// Step 1: sizeof(arr) gives the total size of the array in bytes. Since each int is typically 4 bytes, and there are 9 integers, sizeof(arr) would be 9 * 4 = 36 bytes.
// Step 2: sizeof(arr[0]) gives the size of a single int, which is 4 bytes.
// Step 3: Dividing the total size by the size of one element: 36 / 4 = 9. This means there are 9 elements in the array.