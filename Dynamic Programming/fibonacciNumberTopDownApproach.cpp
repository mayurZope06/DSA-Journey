#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int solveRecMem(int n, vector<int> &dp)
        {
            //base case
            if(n == 0)
            {
                return 0;
            }
            if(n == 1)
            {
                return 1;
            }

            //Step 3: base case k baad, check if ans alreay exist in dp or not
            if(dp[n] != -1)
            {
                return dp[n];
            }

            //Step 2: dp array me ans store karo and return karo
            dp[n] = solveRecMem(n - 1, dp) + solveRecMem(n - 2, dp);
            
            return dp[n]; 
            //recursive relation
        }
        int fib(int n)
        {
            //step 1: create dp array and pass in function
            vector<int> dp(n + 1, -1);
            return solveRecMem(n, dp);
        }
};

int main()
{
    Solution s1;
    cout << s1.fib(25) << endl;
    return 0;
}