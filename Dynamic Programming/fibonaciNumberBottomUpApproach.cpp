#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int solveUsingTabulation(int n)
        {
            //step 1: create dp array.
            vector<int> dp(n + 1, -1);
            
            //step 2: Analyze base case and update dp array
            //base case copy paste -> dp update
            if(n == 0)
            {
                return 0;
            }
            if(n == 1)
            {
                return 1;
            }
            dp[0] = 0;
            dp[1] = 1;

            //step 3: check parameter range, reverse it ans run a loop over it
            //recursion -> n -> 0
            //reverse -> 0 -> n
            for(int i = 2; i <= n; i++)
            {
                //copy paste
                dp[i] = dp[i - 1] + dp[i - 2];
            }

            //answer return 
            return dp[n];
        }
        int fib(int n)
        {
            return solveUsingTabulation(n);
        }
};

int main()
{
    Solution s1;
    cout << s1.fib(25) << endl;
    return 0;
}