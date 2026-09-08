#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
        int solve(vector<int>&sv, int i){
            if(i==sv.size()) return 0;
    
            int ans = INT_MIN;
            int total = 0;
            for(int X = 1;X <= 3; ++X){
                if(i + X - 1 >= sv.size()) break;
                total += sv[i + X - 1];
                ans = max(ans, total - solve(sv, i + X));
            }
    
            return ans;
        }
    
        int solveTD(vector<int>&sv, int i, vector<int>&dp){
            if(i==sv.size()) return 0;
            if(dp[i]!=-1) return dp[i];
            int ans = INT_MIN;
            int total = 0;
            for(int X = 1;X <= 3; ++X){
                if(i + X - 1 >= sv.size()) break;
                total += sv[i + X - 1];
                ans = max(ans, total - solveTD(sv, i + X, dp));
            }
            return dp[i] = ans;
        }

        int solveBU(vector<int>&sv){
            vector<int>dp(sv.size() + 1, 0);
            for(int i=sv.size()-1;i>=0;--i){
                int ans = INT_MIN;
                int total = 0;
                for(int X = 1;X <= 3; ++X){
                    if(i + X - 1 >= sv.size()) break;
                    total += sv[i + X - 1];
                    ans = max(ans, total - dp[i + X]);
                }
                dp[i] = ans;
            }
            return dp[0];
        }
        
        string stoneGameIII(vector<int>& stoneValue) {
            // int ans = solve(stoneValue, 0); // A-B
        
            // vector<int>dp(stoneValue.size() + 1, -1);
            // int ans = solveTD(stoneValue, 0, dp); // A-B
        
            int ans = solveBU(stoneValue);
        
            if(ans > 0) return "Alice";
            if(ans < 0) return "Bob";
            return "Tie";
        }
        
    };
    
    int main() {
        Solution sol;
        vector<int> stoneValue = {1, 2, 3, 7}; // Example test case
        string result = sol.stoneGameIII(stoneValue);
        cout << "Result: " << result << endl; // Expected: "Bob"
        return 0;
    }