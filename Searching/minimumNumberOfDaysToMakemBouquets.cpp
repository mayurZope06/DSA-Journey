#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
    public:
        bool canWeMakeBouquetsWithDDays(vector<int> &bloomDay, int m, int k, int D)
        {
            int counter = 0;
            for (int i = 0; i < bloomDay.size(); i++)
            {
                // check wether the ith flower is bloomed or not
                if (bloomDay [i] <= D)
                {
                    //bloom hogaya hoga
                    counter++;
                }
                if (counter == k)
                {
                    m--; // i can make a Bouquet
                    counter = 0;
                    if (m == 0)
                        break;

                }
                // not bloomed case
                if (bloomDay[i] > D)
                    counter = 0;
                
            }
            return m == 0; // were you able to make m Boiquets
        }
        int minDays(vector<int> &bloomDay, int m, int k)
        {
            long long int requirement = (long long int) m * (long long int ) k;
            if  (bloomDay.size() < requirement)
                return -1;
 
            int start = *min_element (bloomDay.begin(), bloomDay.end()); // at least 1 flower if bloomed
            int end = *max_element(bloomDay.begin(), bloomDay.end()); // all flowers are bloomed
            // pakka bana lunga
            int ans = 0;

            while (start <= end)
            {
                int mid = (start + end) >> 1;
                int day = mid;
                if (canWeMakeBouquetsWithDDays (bloomDay, m , k, day))
                {
                    ans = mid;
                    end = mid - 1;

                }
                else
                    start = mid + 1;
            }
            return ans;
        }
};
int main()
{
    vector <int> bloomDay { 1, 10, 3, 10, 2};
    int m = 3, k = 1;

    Solution s;
    int res= s.minDays(bloomDay, m, k);
    cout<<res;

    return 0;
}