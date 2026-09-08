#include <iostream>
using namespace std;
pair <int,int> checkTwoSum (int arr[], int n, int target)
{
    pair <int,int> ans= make_pair(-1,-1);
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i]+arr[j] == target)
            {
                ans.first = arr[i];
                ans.second = arr[j];

                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    int arr[] = {10,20,30,400};
    int n;
    pair <int,int> ans = checkTwoSum(arr,n,60);
    if (ans.first == -1 && ans.second == -1)
    {
        cout<<"Pair not found"<<endl;
    }
    else
    {
        cout<<"Pair found "<<ans.first<<","<<ans.second<<endl;
    }
    return 0;
}