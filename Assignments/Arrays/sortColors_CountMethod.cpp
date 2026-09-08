#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            // Count Method
            int zeros, ones, twos ;
            zeros = ones = twos = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0 )
                    zeros++;
                    
                if (nums[i] == 1 )
                    ones++;
                else
                    twos++;
            }

            //Spread
            int i = 0;
            while (zeros--)
            {
                nums[i] = 0;
                i++;
            }
            while (ones--)
            {
                nums[i] = 1;
                i++;
            }
            while (twos--)
            {
                nums[i] = 2;
                i++;
            }

        }
};
int main()
{
    vector <int> arr {2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(arr);
    
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";

    return 0;

}