#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool isSafe(int newx, int newy, vector<vector<int>> &m, vector<vector<bool>> &visited, int n)
        {
            if (newx < 0 || newy < 0 || newx >= n || newy >= n)
            {
                // out of bound
                return false;
            }
            if (visited[newx][newy] == true)
            {
                //already visited
                return false;
            }
            if(m[newx][newy] == 0)
            {
                //Blocked Space
                return false;
            }

            return true;
        }

        void solve(vector<vector<int>> &m, vector<vector<bool>> &visited, int n, vector<string> &ans, int srcx, int srcy, int destx, int desty, string output)
        {
            //base case
            if (srcx == destx && srcy == desty)
            {
                //rat reached destination
                //store output string ko ans me
                ans.push_back(output);
                return;
            }

            // 1 case hum solve krenge baki recursion solve krega
            // 1 case -> up, down, left, right

            // UP
            // i, j -> i - 1, j
            int newx = srcx - 1;
            int newy = srcy;
            if(isSafe(newx, newy, m, visited, n))
            {
                visited[newx][newy] = true;
                solve(m, visited, n, ans, newx, newy, destx, desty, output + "U");
                
                //wapas aaunga toh visted toh revert krna padega
                //backtracking
                visited[newx][newy] = false;
            }

            // DOWN
            // i, j -> i + 1, j
            newx = srcx + 1;
            newy = srcy;
            if(isSafe(newx, newy, m, visited, n))
            {
                visited[newx][newy] = true;
                solve(m, visited, n, ans, newx, newy, destx, desty, output + "D");
                
                //wapas aaunga toh visted toh revert krna padega
                //backtracking
                visited[newx][newy] = false;
            }

            // LEFT
            // i, j -> i, j - 1
            newx = srcx;
            newy = srcy - 1;
            if(isSafe(newx, newy, m, visited, n))
            {
                visited[newx][newy] = true;
                solve(m, visited, n, ans, newx, newy, destx, desty, output + "L");
                
                //wapas aaunga toh visted toh revert krna padega
                //backtracking
                visited[newx][newy] = false;
            }

            // RIGHT
            // i, j -> i, j + 1
            newx = srcx;
            newy = srcy + 1;
            if(isSafe(newx, newy, m, visited, n))
            {
                visited[newx][newy] = true;
                solve(m, visited, n, ans, newx, newy, destx, desty, output + "R");
                
                //wapas aaunga toh visted toh revert krna padega
                //backtracking
                visited[newx][newy] = false;
            }
        }

        vector <string> findPath(vector<vector<int>> &m, int n)
        {
            vector <string> ans;
            vector<vector<bool>> visited(n, vector<bool> (n, 0));

            //rat ke row and col index ke liye niche wale 2 var le raha hu
            int srcx = 0;
            int srcy = 0;

            //main yaha pr galti krta hu
            //start me Rat(0, 0) pr hoga, thats why visited truemark karo
            visited[0][0] = true;

            //destination ke row and col index ke liye 2 var us ekrra hu
            int destx = n - 1;
            int desty = n - 1;

            //answer build up krne ke liye string 
            string output = "";

            //important case
            if (m[0][0] == 0)  // if (m[0][0] == 0 || m[n-1][n-1] == 0) // destination blocked edege case
                return ans;
            
            //functiopn call
            solve(m, visited, n, ans, srcx, srcy, destx, desty, output);

            return ans;
        }
};

int main()
{
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = 4; // m.size()
    
    Solution s1;

    vector<string> result = s1.findPath(m, n);
    for (string i: result)
    {
        cout << i << " ";
    }

    return 0;
}