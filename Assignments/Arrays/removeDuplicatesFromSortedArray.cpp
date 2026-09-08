#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
    public:
    int removeDuplicates( vector <int> &nums)
    {
        int i = 1, j = 0;
        // two pointers

        while (i < nums.size())
        {
            if (nums[i] == nums [j])
                ++i;
            else    
                nums[++j] = nums[i++];

            // else{
            //     j++;
            //     nums[j] = nums[i];
            //     i++;
            // }
        }
        return j + 1;
    }
};
int main()
{
    vector <int> nums {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;
    s.removeDuplicates(nums);
    for (int a : nums)
        cout<<a<<" ";
    cout<<endl;
    // int result = s.removeDuplicates(nums);
    // cout<<result<<endl;
    return 0;
}