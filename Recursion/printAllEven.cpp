#include <iostream>
using namespace std;

void printAllEvens (int arr[], int n, int index)
{
    //base case
    if (index == n)
        return;
    
    if (arr[index] % 2 ==0 ) // or if((arr[index]) & 1)
        cout<<arr[index]<<" ";

    printAllEvens(arr, n, index + 1);
}
int main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int size = 7;
    int index = 0;
    printAllEvens(arr, size, index);

    return 0;
}