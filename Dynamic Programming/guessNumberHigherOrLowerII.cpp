#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    public:
        int solveusingRec(int s, int e)
        {
            //base case
            if(s >= e)
            {
                return 0;
            }

            //1 case hum solve krenge
            int ans = INT_MAX;
            for(int i = s; i < e; i++)
            {
                ans = min(ans, i + max(solveusingRec(s, i - 1), solveusingRec(i + 1, e)));
            }
            return ans;
        }

        int solveusingMem(int s, int e, vector<vector<int> >& dp)
        {
            //base case
            if(s >= e)
            {
                return 0;
            }

            if(dp[s][e] != -1)
            {
                return dp[s][e];
            }
            //1 case hum solve krenge
            int ans = INT_MAX;
            for(int i = s; i < e; i++)
            {
                ans = min(ans, i + max(solveusingMem(s, i - 1, dp), solveusingMem(i + 1, e, dp)));
            }
            dp[s][e] = ans;
            return dp[s][e];
        }

        int solveusingTab(int n)
        {
            vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
            
            for(int s = n; s >= 1; s--)
            {
                for(int e = 1; e <= n; e++)
                {
                    if(s >= e)
                    {
                        continue;
                    }
                    else
                    {
                        int ans = INT_MAX;
                        for(int i = s; i < e; i++)
                        {
                            ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
                        }
                        dp[s][e] = ans;
                    }
                }
            }
            return dp[1][n];
        }

        int getMoneyAmount(int n) 
        {
            vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
            // int ans = solveusingRec(1, n);
            //int ans = solveusingMem(1, n, dp);
            int ans = solveusingTab(n);
            return ans;
        }
};

int main()
{
    int n = 10;
    Solution s1;
    cout << s1.getMoneyAmount(n);
    return 0;
}