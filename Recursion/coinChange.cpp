#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    public:
        int solve (vector <int> &coins, int amount)
        {
            if (amount == 0)
                return 0;

            int minCoinAns = INT_MAX;

            for (int i = 0; i  < coins.size(); i++)
            {
                int coin = coins[i];

                if (coin <= amount)
                {
                    int recusionAns = solve(coins, amount - coin);

                    if (recusionAns != INT_MAX)
                    {
                        int coinUsed = 1 + recusionAns;
                        minCoinAns = min (minCoinAns, coinUsed);
                    }
                }
            }
            return minCoinAns;
        }
        int coinChange(vector <int> &coins, int amount)
        {
            int ans = solve(coins, amount);
            if (ans == INT_MAX)
            {
                return -1;
            }
            return ans;
        }
};
int main()
{
    vector <int>coins {2, 5, 1};
    int amount = 6;

    Solution s;
    int res = s.coinChange(coins, amount);
    cout << res << endl;

    return 0;
}