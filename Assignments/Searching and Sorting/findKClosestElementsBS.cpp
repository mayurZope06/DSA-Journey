#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int lowerBound (vector<int> &arr, int x)
        {
            int start = 0, end = arr.size() - 1;
            int ans = end;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                if(arr[mid] >= x)
                {
                    ans = mid;
                    end = mid - 1;
                }
                else if(x > arr[mid])
                    start = mid + 1;
                else
                    end = mid -1;
            }
            return ans;
        }
        vector<int> bs_Method (vector<int> &arr, int k, int x)
        {
            // lowerbound.
            int h = lowerBound(arr, x);
            int l = h - 1;
            while (k--)
            {
                if (l < 0)
                    h++;
                else if (h >= arr.size())
                    l--;
                else if (x - arr[l] > arr[h] - x)
                    h++;
                else
                    l--;
            }
            return vector<int> (arr.begin() + l + 1, arr.begin() + h);
        }
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            return bs_Method(arr, k, x);
        }
};
int main()
{
    // vector<int> arr {1, 2, 3, 4, 5};
    // int k = 4;
    // int x = 3;
    vector<int> arr {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int x = 35;
    Solution s1;
    vector<int>  res = s1.findClosestElements(arr, k, x);
    for (int a: res)
        cout<<a<<" ";
    return 0;
}