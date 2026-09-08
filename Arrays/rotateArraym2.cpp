// reverse method

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    public:
        void rotate (vector<int> &nums, int k)
        {
            int n = nums.size();
            k = k % n;
            // 1. reverse all
            reverse (nums.begin(), nums.end());
            // 2. reverse first k
            reverse(nums.begin(), nums.begin() + k);
            // 3. reverse first n-k
            reverse(nums.begin() + k, nums.end());

        }
};
int main()
{
    vector <int> arr {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution s1;
    s1.rotate(arr, k);

    for(int a : arr)
        cout<<a<<" ";
    
    cout<<endl;
    return 0;
}