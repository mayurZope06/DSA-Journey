#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int solveUsingTabSpaceOptimized(int n)
        {
            if(n == 0)
            {
                return 0;
            }
            if(n == 1)
            {
                return 1;
            }

            int prev = 0;
            int curr = 1;

            for(int i = 2; i <= n; i++)
            {
                int ans = curr + prev;
                prev = curr;
                curr = ans;
            }
            return curr;
        }
        int fib(int n)
        {
            return solveUsingTabSpaceOptimized(n);
        }
};

int main()
{
    Solution s1;
    cout << s1.fib(25) << endl;
    return 0;
}