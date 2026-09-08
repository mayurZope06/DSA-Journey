#include <iostream>
using namespace std;

int binarySearchRecursive (int arr[], int n,  int s, int e, int target)
{
    //base case
    if (s > e)
        return -1;
        
    int mid = (s + e) / 2;

    if (arr[mid] == target)
        return mid;

    if(target > arr[mid])
        //right
        return binarySearchRecursive(arr, n, mid + 1, e, target);
    else
        //left
        return binarySearchRecursive(arr, n , s, mid - 1, target);
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int target = 50;
    int s = 0, e = size - 1;
    int ans = binarySearchRecursive(arr, size, s, e, target);
    cout<<ans;

    return 0;
}