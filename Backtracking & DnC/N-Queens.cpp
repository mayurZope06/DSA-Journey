#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        unordered_map<int, bool> rowCheck;
        unordered_map<int, bool> lowerDiagonalCheck;
        unordered_map<int, bool> upperDiagonalCheck;

        void storeSolution(vector<vector<string>> &ans, vector<vector<char>> &board, int n)
        {
            vector<string> tempAns;
            for (int i = 0; i < n; i++)
            {
                string output = "";
                for(int j = 0; j < n; j++)
                {
                    output.push_back(board[i][j]);
                }
                // string is ready
                tempAns.push_back(output);
            }
            // vector of string is ready
            ans.push_back(tempAns);
        }

        bool isSafe(int row, int col, vector<vector<char>> &board)
        {
            // check for row
            if(rowCheck[row] == true)
            {
                // not safe
                return false;
            }
            // check for upper diagonal
            if(upperDiagonalCheck[row - col] == true)
            {
                // not safe
                return false;
            }
            // check for lower disagonal
            if(lowerDiagonalCheck[row + col] == true)
            {
                // not safe
                return false;
            }
            // else safe to place
            return true;
        }

        void solve (int n, vector<vector<char>> &board, vector<vector<string>> &ans, int col)
        {
            // base case
            if (col >= n)
            {
                // all queens are placed
                // store board arrangement in ans
                storeSolution(ans, board, n);
                return;
            }
            // 1 case hum solve krenge baaki recursion
            // mere pass col ka index hai, uss column me konsi row me queen ko place krna hai vo yaha decide krre hai
            for (int row = 0; row < n; row++)
            {
                // hr row pr queen ko place krke dekhunga
                if(isSafe(row, col, board))
                {
                    board[row][col] = 'Q';
                    rowCheck[row] = true;
                    lowerDiagonalCheck[row + col] = true;
                    upperDiagonalCheck[row - col] = true;

                    // baaki kon sambhalega
                    // recusion
                    solve(n, board, ans, col + 1);

                    // backtrack -> ye mai bhul jata hu
                    board[row][col] = '.';
                    rowCheck[row] = false;
                    lowerDiagonalCheck[row + col] = false;
                    upperDiagonalCheck[row - col] = false;
                }
            }
        }
        vector<vector<string>> solvedNQueens(int n)
        {
            vector<vector<string>> ans;

            //board
            vector<vector<char>> board (n, vector<char>(n, '.'));

            //start picking Queen with 0th column
            int col = 0;
            solve(n, board, ans, col);

            return ans;
        }
};

int main()
{
    int n = 4;
    Solution s1;

    vector<vector<string>> result = s1.solvedNQueens(n);

    for (auto i: result)
    {
        for(string j: i)
        {
            cout << j << endl; //cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}