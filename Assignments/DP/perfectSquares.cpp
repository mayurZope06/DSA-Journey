#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
    public:
        //TD
        int numSquareHelperTD(int n, vector<int> &dp)
        {
            // base
            if(n == 0)
                return 1;

            if(n < 0) 
                return 0;

            if(dp[n] != -1)
                return dp[n];

            int ans = INT_MAX;
            int i = 1;
            int end = sqrt(n);

            while(i <= end)
            {
                int perfectSquare = i * i;
                int numberOfPerfectSquares = 1 + numSquareHelperTD(n - perfectSquare, dp);

                if(numberOfPerfectSquares < ans)
                {
                    ans = numberOfPerfectSquares;
                }
                ++i;
            }
            dp[n] = ans;
            return dp[n];
        }

        //BU
        int numSquareHelperBU(int n, vector<int> &dp)
        {
            dp[0] = 1;

            for(int i = 1; i <= n; ++i)
            {
                int ans = INT_MAX;
                int start = 1;
                int end = sqrt(i);

                while(start <= end)
                {
                    int perfectSquare = start * start;
                    int numberOfPerfectSquares = 1 + dp[i - perfectSquare];

                    if(numberOfPerfectSquares < ans)
                    {
                        ans = numberOfPerfectSquares;
                    }
                    ++start;
                }
                dp[i] = ans;
                
            }
            return dp[n];
        }

        int numSquares(int n)
        {
            vector<int> dp(n + 1, -1);
            //return numSquareHelperTD(n, dp) - 1;
            return numSquareHelperBU(n, dp) - 1;
        }
};

int main()
{
    int n = 12;
    Solution s1;

    cout << s1.numSquares(n);
    return 0;
}