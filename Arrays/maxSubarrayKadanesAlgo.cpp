#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
    public:
        int kadaneAlgo(vector<int> &nums)
        {
            int ans = INT_MIN;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                int num = nums[i];
                sum += num;
                ans = max(ans, sum);

                if(sum < 0)
                    sum = 0;

            }
            return ans;
        }
        int maxSubArray (vector <int> &nums)
        {
            return kadaneAlgo(nums);
        }
};
int main()
{
    vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s1;
    int  ans = s1.maxSubArray(nums);
    cout<<"Maximum Subarray: "<<ans<<endl;

    return 0;
}