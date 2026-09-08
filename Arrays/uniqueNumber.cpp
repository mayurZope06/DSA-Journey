#include <iostream>
using namespace std;
// to find unique number
int findUniqueNumber(int arr[], int n)
{
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()  
{
    int arr[] = {2,4,1,4,1};
    int size = 5;
    int ans = findUniqueNumber(arr, size);
    cout<<"Unique number is :"<<ans <<endl;

    return 0;
}