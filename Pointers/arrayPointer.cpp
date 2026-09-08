#include <iostream>
using namespace std;

int main()
{
    int arr[5] = { 1, 2, 3, 4 ,5};
    cout<<"Base Address: "<< arr<<endl;
    cout<<&arr<<endl;

    int *ptr = arr; // ptr is pointing to the first element of the array

    ptr++; // it will be incremented by 4 byte
    cout<<"Base Address + 1: " << ptr<<endl;

    int (*p)[5] = &arr; // p is pointing to whole array of size 5
    cout<< "Base add of full array:" << p<<endl;

    p++;
    cout<< p << endl;

    return 0;
}