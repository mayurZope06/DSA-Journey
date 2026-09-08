#include <iostream>
using namespace std;

void rotateArray (int arr[], int size, int n)
{
    n = n % size;
    if (n == 0)
    {
        return;
    }
    int temp[10000];
    int index = 0;

    for (int i = size - n; i < size; i++)
    {
        temp [index] = arr[i];
        index++;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        if (i-n >= 0)
        {
            arr[i] = arr[i-n];
        }
    }

    for (int i = 0; i<n; i++)
    {
        arr[i] = temp[i];
    }
}
int main()
{
    int arr[]= {10,20,30,40,50,60};
    int size = 6;
    int n = 2;
    cout<<"Before:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rotateArray(arr,size,n);
    cout<<"After:"<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}