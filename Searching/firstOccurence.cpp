#include <iostream>
using namespace  std;
void findFirstOccurence (int arr[], int n, int target, int &ansIndex)
{
    int s = 0;
    int e =n - 1;
    int mid = s + (e-s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target )
        {
            ansIndex = mid;
            e = mid -1;
        }
        if (target > arr[mid])
        {
            s = mid +1;
        }
        if (target < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
}
int main()
{
    int arr[] = {5, 10, 20, 20, 20, 20, 20, 30, 40, 50, 60};
    int n = 11;
    int target = 20;
    int ansIndex = -1; // -1 means not found
    // applying binary search means array is sorted already
    findFirstOccurence(arr, n, target, ansIndex);
    cout<<"First Occurence Index: "<<ansIndex<<endl;

    return 0 ;
}
