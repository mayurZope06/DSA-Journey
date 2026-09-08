#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void solve (vector<vector<int>> &ans, vector<int> &curr, int k, int start, int n)
        {
            if (k == 0)
            {
                ans.push_back(curr);
                return;
            }
            // ek case
            for (int i = start; i <= n; i++)
            {
                curr.push_back(i);
                solve(ans, curr, k - 1, i + 1, n);
                curr.pop_back();
            }
        }
        vector<vector<int>> combine(int n, int k)
        {
            vector<vector<int>> ans;
            vector<int> curr;
            solve(ans, curr, k, 1, n);
            return ans;
        }
};
int main()
{
    int n = 4;
    int k = 2;
    Solution s1;
    vector<vector<int>> res = s1.combine(n, k);

    for (auto a: res)
    {
        for(auto b: a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}