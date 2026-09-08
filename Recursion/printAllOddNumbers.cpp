#include <iostream>
using namespace std;

void printAllOdds (int arr[], int n, int index)
{
    //base case
    if (index == n)
        return;
    
    if((arr[index]) & 1)
        cout<<arr[index]<<" ";

    printAllOdds(arr, n, index + 1);
}
int main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int size = 7;
    int index = 0;
    printAllOdds(arr, size, index);

    return 0;
}