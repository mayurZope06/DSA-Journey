// use this two pointer approach
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
    public:
        bool twoSum2PointerApproach(int arr[], int n, int x)
        {
            int l = 0;
            int h = n -1;
            while (l < h)
            {
                int sum = arr[l] + arr[h];
                if (sum == x)
                    return true;
                else if (sum > x)
                    h--;
                else    
                    l++;
            }
            return false;

        }
        bool hasArrayTwoCandidates (int arr[], int n, int x)
        {
            sort (arr, arr + n);
            return twoSum2PointerApproach(arr, n, x);
        }
};
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof (int);
    int x = 16;

    Solution s;
    bool result = s.hasArrayTwoCandidates(arr, n, x);
    cout<<result<<endl;
    return 0;
}