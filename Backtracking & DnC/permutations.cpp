#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        void solve(vector<int> &nums, vector<vector<int>> &ans, int i)
        {
            // base case
            if (i >= nums.size())
            {
                ans.push_back(nums);
                return;
            }

            for (int j = i; j < nums.size(); j++)
            {
                swap(nums[i], nums[j]);
                solve(nums, ans, i + 1);

                // backtrack
                swap(nums[i], nums[j]);
            }
        }
        
        vector<vector<int>> permute (vector<int> &nums)
        {
            vector<vector<int>> ans;
            int i = 0;
            solve(nums, ans, i);
            return ans;
        }
};

int main()
{
    vector <int> nums = {1, 2, 3};

    Solution s1;
    vector<vector<int>> result = s1.permute(nums);

    for( const auto &i: result)
    {
        for (int j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}