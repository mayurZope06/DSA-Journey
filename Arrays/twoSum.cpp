#include <iostream>
using namespace std;
bool checkTwoSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {10,20,30,40};
    int n = 4;
    bool ans = checkTwoSum(arr,n,60);
    if (ans == true)
    {
        cout<<"Pair Found"<<endl;
    }
    else{
        cout<<"Pair not found"<<endl;
    }
    return 0;
}