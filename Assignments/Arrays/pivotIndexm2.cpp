#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int prefixSumApproach(vector<int> &nums)
        {
            vector <int> lsum (nums.size(), 0);
            vector <int> rsum (nums.size(), 0);

            //cal lsum array
            for (int i = 1; i < nums.size(); ++i)
                lsum[i] = lsum[i - 1] + nums[i - 1];
            //cal rsum array
            for (int i = nums.size() - 2; i >= 0; --i)
                rsum[i] = rsum[i+1] + nums[i + 1];
            
            //check karte hai
            for (int i = 0; i < nums.size(); ++i)
            {
                if (lsum[i] == rsum[i])
                    return i;
            }
            return -1;

        }
        int pivotIndex (vector<int> &nums)
        {
            return prefixSumApproach(nums);
        }
};
int main()
{
    vector <int> nums {1, 7, 3, 6, 5, 6};
    Solution s;
    int result = s.pivotIndex(nums);
    cout<<"Pivot Index: "<<result<<endl;

    return 0;
}
