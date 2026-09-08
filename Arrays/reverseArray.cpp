#include <iostream>
#include <algorithm>
using namespace std;
void reverseArray (int arr [], int n)
{
    int l = 0, h = n-1;
    while (l<h)
    {
        swap (arr[l],arr[h]);
        l++;
        h--;
    }
    /*  pro ki tarah code 
    while (l<h)
        swap(arr[l++],arr[h--]);   */
}
    
int main()
{
    // Method 1
    int arr[8] = {10,20,30,40,50,60,70,80};
    int n =sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr,n);
    
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }

    // Method 2 STL C++ lib
    int arr2 [7] = {10,20,30,40,50,60,70};
    int nn = sizeof(arr2) /sizeof(arr2[0]);
    reverse(arr2,arr2+nn);
    for(int i = 0; i < nn; i++)
    {
        cout<<arr2[i]<<endl;
    }

    return 0;
    
}