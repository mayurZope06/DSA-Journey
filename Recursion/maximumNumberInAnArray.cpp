#include <iostream>
#include <climits>
using namespace std;

void maxInArray(int arr[], int size,int index,int &maxi)
{
    //base case
    if(index == size)
    {
        return;
    }
    //recursive relation
    maxi = max(maxi, arr[index]);

    maxInArray(arr, size, index + 1, maxi);
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int index = 0;
    int maxi = INT_MIN;
    maxInArray(arr, size, index, maxi);

    cout<<"Max no:"<<maxi;

    return 0;
}