#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    public:
    int solve(vector<int>& piles, int i, int M, int alice){
        if(i == piles.size()) return 0;
    
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
    
        for(int X=1;X<=2*M;++X){
            if(i+X-1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice)
                ans = max(ans, total + solve(piles, i + X, max(X, M), !alice));
            else
                ans = min(ans, solve(piles, i + X, max(X, M), !alice));
        }
        return ans;
    }

    int solveTD(vector<int>& piles, int i, int M, int alice, vector<vector<vector<int>>>& dp){
        if(i == piles.size()) return 0;
        if(dp[i][M][alice] != -1) return dp[i][M][alice];
    
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
    
        for(int X=1;X<=2*M;++X){
            if(i+X-1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice)
                ans = max(ans, total + solveTD(piles, i + X, max(X, M), !alice, dp));
            else
                ans = min(ans, solveTD(piles, i + X, max(X, M), !alice, dp));
        }
        return dp[i][M][alice] = ans;
    }

    int solveBU(vector<int>& piles){
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));
    
        for(int i = n - 1; i >= 0; --i){
            for(int M = 1; M <= n; ++M){
                for(int alice = 0; alice < 2; ++alice){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;
    
                    for(int X = 1; X <= 2 * M; ++X){
                        if(i + X - 1 >= n) break;
                        total += piles[i + X - 1];
                        if(alice){
                            ans = max(ans, total + dp[i + X][max(X, M)][!alice]);
                        } else {
                            ans = min(ans, dp[i + X][max(X, M)][!alice]);
                        }
                    }
                    dp[i][M][alice] = ans;
                }
            }
        }
        return dp[0][1][1];
    }
    
    int stoneGameII(vector<int>& piles) {
        // return solve(piles, 0, 1, true);
        // vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        // return solveTD(piles, 0, 1, true, dp);
        return solveBU(piles);
    }
};

int main()
{
    vector<int> piles = {2,7,9,4,4};
    Solution s1;
    cout << s1.stoneGameII(piles);
    return 0;
}