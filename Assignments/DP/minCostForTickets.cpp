#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int mincostTickets_helperTD(vector<int> &days, vector <int> &costs, int i, vector<int> &dp)
        {
            //base
            if( i >= days.size())
                return 0;

            if(dp[i] != -1)
                return dp[i];

            //Sol for a case

            //1 Day Pass Taken
            int cost1 = costs[0] + mincostTickets_helperTD(days, costs, i + 1, dp);

            //7 Day pass taken
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost7 = costs[1] + mincostTickets_helperTD(days, costs, j, dp);
            
            //30 day pass taken
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost30 = costs[2] + mincostTickets_helperTD(days, costs, j, dp);

            dp[i] =  min(cost1, min(cost7, cost30));
            return dp[i];
        }

        int mincostTickets_helperBU(vector<int> &days, vector <int> &costs, int i, vector<int> &dp)
        {
            dp[days.size()] = 0;

            for(int i = days.size() - 1; i >= 0; --i)
            {
                //Sol for a case

                //1 Day Pass Taken
                int cost1 = costs[0] + dp[i + 1];

                //7 Day pass taken
                int passEndDay = days[i] + 7 - 1;
                int j = i;
                while(j < days.size() && days[j] <= passEndDay)
                {
                    j++;
                }
                int cost7 = costs[1] + dp[j];
                
                //30 day pass taken
                passEndDay = days[i] + 30 - 1;
                j = i;
                while(j < days.size() && days[j] <= passEndDay)
                {
                    j++;
                }
                int cost30 = costs[2] + dp[j];

                dp[i] =  min(cost1, min(cost7, cost30));
            }
            return dp[0];
        }

        int mincostTickets(vector<int> &days, vector <int> &costs)
        {
            vector<int> dp(days.size() + 1, -1);
            //return mincostTickets_helperTD(days, costs, 0, dp);
            return mincostTickets_helperBU(days, costs, 0, dp);
        }
};

int main()
{
    vector <int> days = {2, 5};
    vector<int> costs = {1, 4, 25};

    Solution s1;
    cout << s1.mincostTickets(days, costs);
    return 0;
}