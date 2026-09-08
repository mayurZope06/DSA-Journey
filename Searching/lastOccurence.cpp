#include <iostream>
using namespace std;
void findLastOccurence (int arr[], int n, int target, int &ansIndex)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target)
        {
            ansIndex = mid;
            s = mid + 1;

        }
        if (target > arr[mid])
            s = mid +1;
        if ( target < arr[mid])
            e = mid - 1;
        // ye mai bhul jata hu
        mid = s + (e-s) / 2;
    }
} 
int main()
{
    int arr[] = { 5, 10, 20, 20, 20, 20, 20, 30, 40, 50, 60};
    int n= 11 ;
    int target = 20;

    int ansIndex = -1; // -1 means target not found
    findLastOccurence(arr, n, target, ansIndex);
    cout<<"Last Occurence index: "<<ansIndex<<endl;
    return 0;
}
