#include <iostream>
using namespace std;

void print(int arr [], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout<<arr[index]<<" ";
    }
}
void solve1(int arr[],int size)
{
    for (int index = 0; index < size; index++)
    {
        arr[index] = arr[index] * 10;
    }
}
int main()
{
    int arr[]={10,20,30,40,50};
    int size = 5;
    solve1(arr,size);
    print(arr,size);
    return 0;
}