#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int peakIndexInMountainArray (vector <int> &arr)
        {
            int s = 0;
            int e = arr.size() - 1;
            int ans = -1;

            while (s <= e)
            {
                int mid = (s + e) >> 1;
                if (arr[mid] < arr[mid + 1])
                    s = mid +1;
                else if (arr[mid] < arr[mid - 1])
                    e = mid - 1;
                else
                {
                    ans = mid;
                    break;
                }
            }
            return ans;
        }
};
int main()
{
    vector  <int> arr {10, 20, 70, 60, 50, 30, 15, 5};
    int result;
    Solution s1;
    result = s1.peakIndexInMountainArray(arr);
    cout<<"Peak Index: "<<result<<endl;

    return 0;
}