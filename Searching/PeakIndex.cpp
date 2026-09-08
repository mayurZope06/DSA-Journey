#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int peakIndexInMountainArray(vector <int> &arr)
        {
            int s = 0;
            int n = arr.size();
            int e = n - 1;
            int mid = s + (e-s) / 2;

            while (s < e)
            {
                if (arr[mid] < arr[mid + 1])
                    s = mid + 1;
                else
                    e = mid;
                mid = s + (e-s) / 2;
            }
            return mid;
        }
};
int main()
{
    vector <int> arr{10, 20, 30, 80, 70, 55, 45, 35, 25};
    Solution s1;

    int result = s1.peakIndexInMountainArray(arr);
    cout<<"Peak Index in a Mountain Array: "<<result<<endl;

    return 0;
}