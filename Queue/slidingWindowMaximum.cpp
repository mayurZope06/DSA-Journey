#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector <int> maxSlidingWindow(vector<int> &nums, int k)
        {
            deque<int> dq;
            vector<int> ans;

            //process first Window
            for(int i = 0; i < k; i++)
            {
                int element = nums[i];
                //ye element toh abhi queue k andar insert hoga hi hoga but hum ek kaam kr skte hai,
                //abhi tk jitne bhi queue bani hui h usme se check krlo konse faltu elements hai 
                //and unko pop karwado
                // faltu -> current element se chotte elements jo hai

                while(!dq.empty() && nums[dq.back()] < element)
                {
                    dq.pop_back();
                }
                //current element toh insert krna hai hi h
                dq.push_back(i);
            }
            //get answer for first window
            int index = dq.front();
            int element = nums[index];
            ans.push_back(element);

            //process remaning windows
            for(int i = k; i < nums.size(); i++)
            {
                //removal
                if(!dq.empty() && dq.front() < i - k + 1)
                {
                    dq.pop_front();
                }

                //addition
                int element = nums[i];

                while(!dq.empty() && nums[dq.back()] < element)
                {
                    dq.pop_back();
                }
                //current element toh insert krna hi h
                dq.push_back(i);
                
                //ans store
                int index = dq.front();
                int ansElement = nums[index];
                ans.push_back(ansElement);
            }
            return ans;
        }
};

int main()
{
    vector <int> nums {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution s1;
    vector< int> res = s1.maxSlidingWindow(nums, k);
    for(auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}