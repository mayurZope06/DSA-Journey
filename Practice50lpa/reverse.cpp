#include <iostream>
using namespace std;
void reverseArr(int arr[], int n) {
    int l = 0; 
    int h = n - 1;

    while(l < h) {
        swap(arr[l++], arr[h--]);
    }

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int  n = sizeof(arr) / sizeof(arr[0]);
    reverseArr(arr, n);
    return 0;
}