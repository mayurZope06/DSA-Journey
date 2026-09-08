#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;

        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
                ans.push_back(nums[i]);
            else
            {
                // find the index of just >= the ith element
                auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
                int index = it - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};

int main()
{
    vector <int>nums {10,9,2,5,3,7,101,18};
    Solution s;
    int res = s.lengthOfLIS(nums);
    cout << res << endl;

    return 0;
}