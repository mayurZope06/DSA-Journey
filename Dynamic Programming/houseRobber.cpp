#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int solve(vector<int> &nums, int i)
        {
            //base case
            if(i >= nums.size())
                return 0;

            //1 case main solve, baaki recursion 
            //inc - excl
            int include = nums[i] + solve(nums, i + 2);
            int exclude = 0 + solve(nums, i + 1);
            int finalAns = max(include, exclude);

            return finalAns;
        }

        //1-D DP
        //top-down approach -> rec + mem
        int solveMem(vector<int> &nums,int i, vector<int> &dp)
        {
            //base case
            if(i >= nums.size())
                return 0;

            //Step 3: check if ans already exists
            if(dp[i] != -1)
            {
                return dp[i];;
            }

             //1 case main solve, baaki recursion 
            //inc - excl
            int include = nums[i] + solve(nums, i + 2);
            int exclude = 0 + solve(nums, i + 1);
            
            //Step 2: store and return ans in DP
            dp[i] = max(include, exclude);

            return dp[i];
        }

        int solveUsingTab(vector<int> &nums)
        {
            int n = nums.size();
            //Step 1: create DP array
            vector<int> dp(n + 2, -1);

            //indexes -> 0 to n + 1
            //Step 2: base case analyse, and change dp array ko accordingly
            dp[n] = 0;
            dp[n + 1] = 0;

            for(int i = n - 1; i >= 0; i--)
            {
                //logic copy paste
                int include = nums[i] + dp[i + 2];
                int exclude = 0 + dp[i + 1];
                dp[i] = max(include, exclude);
            }
            return dp[0];
        }
        
        int solveUsingTabSO(vector<int> &nums)
        {
            int n = nums.size();

            int next1 = 0;
            int next2 = 0;

            for(int i = n - 1; i >= 0; i--)
            {
                //logic copy paste
                int include = nums[i] + next2;
                int exclude = 0 + next1;
                int curr = max(include, exclude);

                //shifting -> ye mai bhul jata hu
                next2 = next1;
                next1 = curr;
            }

            return next1;
        }
        
        int rob(vector<int>& nums) 
        {
           // return solve(nums, 0);
            int n = nums.size();
            //step1: createa and pass DP array
            // vector<int> dp(n+1, -1);
            // int i = 0;
            // return solveMem(nums, i, dp);
            return solveUsingTabSO(nums);
        }
};     

int main()
{
    vector <int> nums = {1, 2, 3, 1};
    Solution s;
    int res = s.rob(nums);

    cout << res <<endl;
    
    return 0;
}