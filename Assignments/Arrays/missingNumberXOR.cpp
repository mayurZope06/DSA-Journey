#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int xorr (vector<int> &nums)
        {
            int ans = 0;

            // 1. XOR all values of array 
            for (int i = 0; i < nums.size(); ++i)
            {
                ans ^= nums[i];
            }

            // 2. XOR all range items [0, N]
            int n = nums.size();
            for (int i = 0; i <= n; i++)
            {
                ans ^= i;
            }
            return ans;
        }
        int missingNumber(vector <int> &nums)
        {
            return xorr(nums);
        }
};
int main()
{
    vector <int> nums {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution s;
    int result = s.missingNumber(nums);

    cout<<"Missing Element: "<< result <<endl;
    return 0 ;
}
