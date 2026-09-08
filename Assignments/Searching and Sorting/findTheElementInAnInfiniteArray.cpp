// Exponential search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int x)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == x)
            return mid;
        
        else if (x > arr[mid])
            start = mid + 1;
        else    
            end = mid - 1;
    }
    return -1;
}

int ExpSearch(int arr[],int n, int x)
{
    int i = 0, j = 1;
    while (arr[j] < x)
    {
        i = j;
        j *= 2;
    }
    binarySearch(arr, i, j, x);
}
int main()
{
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(int);
    int x = 56;
    int ans = ExpSearch(a, n, x);
    cout<<ans<<endl;

    return 0;
}