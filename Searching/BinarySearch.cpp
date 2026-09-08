#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int search(vector<int> &arr, int target)
        {
            int n = arr.size();
            int s = 0;
            int e = n-1;
            int mid = s + (e-s) / 2;

            while(s<= e)
            {
                if (arr[mid] == target)
                    return mid;
                if (target > arr[mid])
                    s = mid + 1;
                else  if (target < arr[mid])
                    e = mid - 1;
                mid = s + (e-s) / 2;

            }
            return -1;

        }
};
int main()
{
    vector <int> arr = {-1,0,3,5,9,12};
   // int arr[] = {-1,0,3,5,9,12};
    int target = 9;

    Solution s1;
    int result = s1.search(arr, target);
    if  (result != -1)
        cout<<"Element found at index: "<<result<<endl;
    else    
        cout<<"Element not found."<<endl;

    return 0;
}