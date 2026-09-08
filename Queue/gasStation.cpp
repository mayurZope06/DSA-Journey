#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int start = 0;
            int balance = 0;
            int deficit = 0;

            for(int i = 0; i < gas.size(); i++)
            {
                balance = balance + gas[i] - cost[i];
                //+ve -> balance hai, nothing to worry about
                //-ve -> ye deficit ko darsha raha hai

                if(balance < 0)
                {
                    deficit += abs(balance);
                    //deficit aayah, iska mtlb aage nahi jaa paye,
                    //iska mtlb start update hoga
                    start = i + 1;
                    balance = 0;
                }
            }
            
            if(balance - deficit >= 0)
            {
                return start;
            }
            else
            {
                return -1;
            }
        }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};

    Solution s1;
    cout << s1.canCompleteCircuit(gas, cost);
    return 0;
}