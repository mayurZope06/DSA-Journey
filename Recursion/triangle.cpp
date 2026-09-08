#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int solve(vector<vector<int>> &triangle, int row, int col)
        {
            if(row == triangle.size() - 1)  return triangle[row][col];

            int down = triangle[row][col] + solve(triangle, row + 1, col);
            int plus = triangle[row][col] + solve(triangle, row + 1, col + 1);
            
            return min(down, plus);
        }
        int minimumTotal(vector<vector<int>> &triangle)
        {
            return solve(triangle, 0, 0);
        }
};

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s1;
    int res = s1.minimumTotal(triangle);
    cout << res;
    return 0;
}