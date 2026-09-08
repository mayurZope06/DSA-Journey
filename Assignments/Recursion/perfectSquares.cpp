#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution
{
    public:
        int numSquareHelper(int n)
        {
            // base
            if(n == 0)
                return 1;

            if(n < 0) 
                return 0;

            int ans = INT_MAX;
            int i = 1;
            int end = sqrt(n);
            while(i <= end)
            {
                int perfectSquare = i * i;
                int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);

                if(numberOfPerfectSquares < ans)
                {
                    ans = numberOfPerfectSquares;
                }
                ++i;
            }
            return ans;
        }
        int numSquares(int n)
        {
            return numSquareHelper(n) - 1;
        }
};

int main()
{
    int n = 12;
    Solution s1;

    cout << s1.numSquares(n);
    return 0;
}