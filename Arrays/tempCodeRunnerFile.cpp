#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    public:
        void rotate (vector<vector <int>> &matrix)
        {
            //step 1. transpose
            int nrows = matrix.size();
            int ncols = matrix[0].size();

            for(int i = 0; i < nrows; i++)
            {
                for (int j = 0; j < ncols; j++)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }

            }
            //Step 2. reverse row wise
            for (int i = 0; i < nrows; i++)
            {
                reverse (matrix[i].begin(), matrix[i].end());
            }
        }
};
int main()
{
    
    vector<vector<int>> matrix { {1,2,3},
                                 {4,5,6},
                                 {7,8,9},
                                 
                                };
    int nrows = matrix.size();
            int ncols = matrix[0].size();
    Solution s1;
    s1.rotate (matrix);
    for(int i = 0; i < nrows; i++)
            {
                for (int j = 0; j < ncols; j++)
                {
                    cout<< matrix[i][j]<<" ";
                }
            }


    return 0;
}