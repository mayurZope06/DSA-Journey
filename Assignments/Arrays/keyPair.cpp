// Two Sum
#include <iostream>
using namespace std;
class Solution
{
    public:
        bool twoSum (int arr[], int n, int x)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] + arr[j] == x)
                        return true;
                }
            }
            return false;
        }
        bool hasArrayTwoCandidates(int arr[], int n, int x)
        {
            bool ans = twoSum(arr, n, x);
            return ans;
        }
};
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 6};
    int n = sizeof(arr) / sizeof(int);
    int x = 16;
    Solution s;
    int res = s.hasArrayTwoCandidates(arr, n, x);
    cout<<res;
    return 0;
}
