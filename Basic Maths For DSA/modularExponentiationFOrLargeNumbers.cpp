#include <iostream>
using namespace std;
class Solution
{
    public:
        long long int powMod (long long int x, long long int n, long long int M)
        {
            long long int ans = 1;
            while (n > 0)
            {
                if (n & 1){
                    ans = (ans * x) % M;
                }
                x = (x * x) % M;
                n >>= 1;
            }
            return ans % M;

        }
};
int main()
{
    Solution s1;
    cout<<s1.powMod(3, 2, 4);
    return 0;
}