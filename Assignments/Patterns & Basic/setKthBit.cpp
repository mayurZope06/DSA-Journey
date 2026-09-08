#include <iostream>
using namespace std;

class Solution
{
    public:
        int setKthBit (int N, int K)
        {
            int mask = 1 << K;
            int ans = N | mask;
            return ans;
            // or return N | (1 << K);
        }
};
int main()
{
    int N = 10;
    int K = 2;
    Solution s1;
    int res = s1.setKthBit(N, K);
    cout << res;
    return 0;
}