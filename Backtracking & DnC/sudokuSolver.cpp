#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool isSafe (char digit, int row, int col, vector<vector<char>> &board)
        {
            // rowCheck
            int n = board.size();
            for(int k = 0; k < n; k++)
            {
                if(board[row][k] == digit)
                {
                    // same digit phele se same row me exit krta hai
                    return false;
                }
            }
            // colCheck
            for(int k = 0; k < n; k++)
            {
                if (board[k][col] == digit)
                {
                    // same col me same digit pehle se exist krta hai
                    return false;
                }
            }
            // 3 * 3 sub - box check
            for(int k = 0; k < n; k++)
            {
                if (board[3 * (row / 3) + (k / 3)][3 * (col / 3) + (k % 3)] == digit)
                {
                    //same 3 * 3 k box me same digit exist krta hai 
                    return false;
                }
            }
            // agar teeno rules badia follow ho rahe hai toh  kya hai
            return true;
        }

        bool solve(vector<vector<char>> &board)
        {
            // base case - no need
            // 1 case hum baki recursion sambhal lega
            // empty -> '.'
            for(int i =0; i < board.size(); i++)
            {
                for(int j = 0; j < board[0].size(); j++)
                {
                    // main i,j wali cell pr aagya pr pata kaise lagega k data fill kru ya nahi
                    // sirf empty cell pr fill krenge
                    if(board[i][j] == '.')
                    {
                        //fill this cell, coz its empty
                        // empty cell pr mujhe 1 -> 9 tk digit hit and trial krne hai

                        for(int digit = '1'; digit <= '9'; digit++)
                        {
                            // konsa digit rakh skta hu, ye kaise pata lagega
                            //mujhe bs check krna hai , k konsa digit rakhna safe hai
                            if(isSafe(digit, i, j, board) == true)
                            {
                                // agar safe jai rakhna
                                board[i][j] = digit;

                                // baaki aage sambhalega -> recursion
                                bool aageSolveHoPaya = solve(board);
                                if(aageSolveHoPaya == true)
                                {
                                    // poora board solve hogaya
                                    return true;
                                }
                                else
                                {
                                    // ye wo case hai -> jaha tumne ek digit place krdi h but recursion se aage ka answer false aagaya age board solve nahi ho paya
                                    // backtrack -> shayad maine galat digit rakh diya
                                    board[i][j] = '.';
                                }
                            }
                        }
                        // agara aap yaha pohoch gaye
                        // iska mtlab ye hai -> k 1 -> 9 tk kahi bhi  digit yaha pr fit nahi ho raha
                        //piche kahi galati kari hai
                        return false;
                    }
                }
            }
            // yaha aagaye -> iska mtlab
            // board -> completely fill hogaya hai
            // ans aa chuka hai
            return true;
        }
        void solveSudoku(vector<vector<char>> &board)
        {
            solve(board);
        }
};

int main()
{
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
        Solution s1;
        s1.solveSudoku(board);
        // Print the solved Sudoku
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }

    return 0;
}