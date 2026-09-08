#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    public:
        int solve(vector<vector<int>> &mat, int &target, int sum, int row)
        {
            if (row == mat.size())
            {
                return abs(target - sum);
            }
            int ans = INT_MAX;
            for(int col = 0; col < mat[row].size(); col++)
            {
                int recAns = solve(mat, target, sum + mat[row][col], row + 1);
                ans = min(ans, recAns);
            }
            return ans;
        }
        int minimizeTheDifferencce(vector<vector<int>> &mat, int target)
        {
            int sum = 0, row = 0;
            return solve(mat, target, sum, row);
        }
};

int main()
{
    vector<vector<int>> mat = {
        {2, 1, 3},
        {4, 5, 6},
        {8, 7, 9}
    };
    int target = 13;
    Solution s1;
    int res = s1.minimizeTheDifferencce(mat, target);
    cout << res;
    
    return 0;
}