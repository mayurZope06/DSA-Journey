// Sorting Method
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    public:
    int singleNumber(vector <int> &nums)
    {
        //1.Sorting
        sort (nums.begin(), nums.end());
        int n =nums.size();
        int ans = -1;
        int i = 0;
        while (i  < n)
        {
            if (i+1 < n && nums[i] == nums [i+1])
            {
                i+=2;
            }
            else
            {
                ans = nums[i];
                break;
            }
        }
        return ans;

    }
};
int main()
{
    vector<int> arr {1, 2, 3, 1, 2, 3, 4};
    Solution s1;
    int ans = s1.singleNumber(arr);
    cout<<"Unique Number: "<<ans<<endl;

    return 0;
}