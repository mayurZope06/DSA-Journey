#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int getPivotIndex (vector<int> &arr)
        {
            int s = 0;
            int n = arr.size();
            int e = n - 1;
            int mid = s + (e-s) / 2;

            while (s <= e)
            {
                if (s == e)  // for single element case
                    return s;
                if ( mid + 1 < n && arr[mid] > arr[mid+1])
                    return mid;
                if (arr[s] > arr[mid]) // arr[s] = arr[n+1]
                    e = mid - 1;
                else
                    s - mid + 1;
                mid = s + (e-s) / 2;
            }
            return -1;
            
        }
        int binarySearch (vector <int> &arr, int s, int e, int target)
        {
            int mid = s+ (e-s) / 2;
            while (s <= e)
            {
                if (arr[mid] == target)
                    return mid;
                else if (target > arr[mid])
                    s= mid + 1;
                else // target < arr[mid]
                    e = mid - 1;
                mid = s + (e-s ) / 2;
            }
            return -1;
        }
        int search (vector<int> &arr, int target)
        {
            int pivotIndex = getPivotIndex(arr);

            int n = arr.size();
            
            // line A 
            // Start -> 0 index
            // end -> pivotIndex

            if (target >= arr[0] && target <= arr[pivotIndex])
            {
                int ans = binarySearch(arr, 0, n - 1, target);
                return ans;
            }
            // line B
            // Start -> pivotIndex + 1
            // end -> n - 1
            else
            {
                int ans = binarySearch(arr, pivotIndex + 1, n - 1, target);
                return ans;
            }
            return -1;
        }
};
int main()
{
    vector <int> arr {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution s;
    int result = s.search(arr, target);
    cout<<"Found at Index: "<<result<<endl;
    return 0;
}