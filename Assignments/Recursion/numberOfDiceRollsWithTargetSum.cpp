#include <iostream>
using namespace std;

class Solution
{
    public:
        int numRollsToTarget(int n, int k, int target)
        {
            // base
            if(target < 0)
                return 0;

            if(n == 0 && target == 0)
                return 1;

            if(n == 0 && target != 0)
                return 0;
            
            if(n != 0 && target == 0)
                return 0;

            int ans = 0;
            for(int i = 1; i <= k; i++)
            {
                ans = ans + numRollsToTarget(n - 1, k, target - i);
            }
            return ans;
        }
};

int main()
{
    int n = 3, k = 2, target = 6;
    Solution s1;
    cout << s1.numRollsToTarget(n, k, target);
    return 0;
}