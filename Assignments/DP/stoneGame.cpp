#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool stoneGame(vector<int>& piles) {
            //there will be at least one way by which Alice will win
            //that means, we should return true.
            //bcz problem is asking is there any way that Alice can win.

            return true;
        }
    };

int main()
{
    vector<int> piles = {5,3,4,5};
    Solution s1;
    cout << s1.stoneGame(piles);
    return 0;
}