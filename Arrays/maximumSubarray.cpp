#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
    public:
    int native(vector <int> &nums)
    {
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum = sum + nums[j];
                ans = max(ans, sum);

            }
        }
        return ans;
    }

    int maxSubArray(vector <int> &nums)
    {
        return native (nums);

    }

};
int main()
{
    Solution s1;
    vector<int>nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = s1.maxSubArray(nums);
    cout<<"Maximum Subarry (i.e. largest sum): "<<result<<endl;

    return 0;
}