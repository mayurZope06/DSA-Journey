#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool solve(vector<int> &nums, int i)
        {
            if (i == nums.size() - 1)   return true;
            if (i >= nums.size())   return false;
            bool recAns = false;
            for(int jump = 1; jump <= nums[i]; jump++)
            {
                recAns = recAns || solve(nums, i + jump);
            }
            return recAns;
        }
        bool canJump(vector<int> &nums)
        {
            return solve(nums, 0);
        }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution s1;
    bool res = s1.canJump(nums);
    cout << res;
    return 0;
}