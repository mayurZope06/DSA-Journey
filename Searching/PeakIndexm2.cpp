// Store and Compute
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int peakIndexInMountainArray (vector <int> &arr)
        {
            int n = arr.size();
            int s = 0;
            int e = n - 1;
            int mid = s + (e-s) / 2;

            int ansIndex = -1;
            while (s <= e)
            {
                if (arr[mid] < arr[mid + 1])
                    s = mid + 1;
                else
                {
                    ansIndex = mid;
                    e = mid - 1;
                }
                mid = s + (e - s) / 2;
            }
            return ansIndex;
        };
       

};
int main()
{
    vector <int> arr{10, 20, 30, 80, 70, 55, 45, 35, 25};
    Solution s1;

    int result = s1.peakIndexInMountainArray(arr);
    cout<<"Peak Index in a Mountain Array: "<<result<<endl;

    return 0;
}