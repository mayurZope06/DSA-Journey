#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        bool searchMatrix (vector<vector<int>> &matrix, int target)
        {
             int rows = matrix.size();
             int cols = matrix[0].size();

             int n = rows * cols;
             int s = 0;
             int e = n - 1;
             int mid = s + (e - s) / 2;

             while (s <= e)
             {
                int rowIndex = mid / cols;
                int colInndex = mid % cols;

                if (matrix[rowIndex][colInndex] == target)
                    return true;
                if (target > matrix[rowIndex][colInndex])
                    s = mid + 1;
                else
                    e = mid -1;
                mid = s + (e-s) / 2;
             }
             return false;

        }
};
int main()
{
    vector<vector<int>> martix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 64}};
    int target = 3;
    Solution s;
    bool result = s.searchMatrix(martix, target);
    cout<<result<<endl;
    return 0;
}