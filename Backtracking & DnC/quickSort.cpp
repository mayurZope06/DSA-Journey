#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    public:

        void quickSort(int a[], int start, int end)
        {
            // base case
            if (start >= end)   return;

            int pivot = end;
            int i = start - 1;
            int j = start;

            while (j < pivot)
            {
                if (a[j] < a[pivot])
                {
                    ++i;
                    swap(a[i], a[j]);
                }
                ++j;
            }
            ++i; // i is the right position for the pivot element
            swap(a[i], a[pivot]);

            quickSort(a, start, i - 1);
            quickSort(a, i + 1, end);
        }
};

int main()
{
    int a[] = {7, 2, 1, 8, 6, 3, 5, 4};
    int size = sizeof(a) / sizeof(a[0]);
    int start = 0;
    int end = size - 1;

    Solution s1;
    
    cout << "Before Sorting: " <<endl;
    for(int i: a)
        cout << i << " ";
    cout << endl;

    s1.quickSort(a, start, end);

    cout << "After Sorting: " << endl;
    for(int i: a)
        cout << i << " ";
    cout << endl;

    return 0;
}