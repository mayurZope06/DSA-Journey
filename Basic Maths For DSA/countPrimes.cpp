#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int countPrimes(int n)
        {
            if (n == 0) return 0;

            vector <int> prime(n, true); 
            prime[0] = prime[1] = false;

            int ans = 0;
            for (int i = 2; i < n; i++)
            {
                if (prime[i])
                {
                    ans++;

                    int j = 2 * i;

                    while (j < n)
                    {
                        prime[j] = false;
                        j += i;
                    }
                }
            }
            return ans;
        }
};
int main()
{
    int n = 10;
    Solution s1;
    cout<<s1.countPrimes(n);
    return 0;
}