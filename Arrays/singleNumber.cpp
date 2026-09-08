// unique number
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
    public: 
        int singleNumber(vector <int> &nums)
        {
            //freq table
            unordered_map <int, int> freqMap;

            for (int i = 0; i < nums.size(); i++)
            {
                int num = nums[i];
                freqMap[num] = freqMap[num] + 1;

            }
            unordered_map <int, int> :: iterator it;
            int ans;
            for (it = freqMap.begin(); it != freqMap.end(); it++)
            {
                int key = it -> first;
                int freq = it -> second;

                if (freq == 1)
                {
                    ans = key;
                    break;
                }
                //cout<<key<<" "<<value<<endl;
            }
            return ans;
        }
};
int main()
{
    Solution s1;
    vector <int> nums {4, 1, 2, 1, 2};
    int ans = s1.singleNumber(nums);

    cout<<ans<<endl;

    return 0;
}