#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution 
{
    public:
        int sortingMethod (vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            
            for (int i = 0; i < nums.size(); ++i)
            {
                if (i == nums [i])
                    continue;
                else    
                    return i;
            }
            return nums.size();
        }
        int miossingNumber(vector <int> &nums )
        {
            return sortingMethod(nums);
        }
};
int main()
{
    vector<int> nums {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution s;
    int result = s.miossingNumber(nums);
    cout<<"Missing Number: "<<result<<endl;

    return 0;
}