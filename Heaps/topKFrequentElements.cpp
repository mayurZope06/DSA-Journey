#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            //the freq. of each element 
            unordered_map<int, int> freqMap; // key: element, value: freq;
            for(auto num: nums)
            {
                freqMap[num]++;
            }

            //pair<int, int> -> shows, {freq, num};
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            //iterate over the freq. map & maintain heap of size k
            for(auto entry: freqMap)
            {
                minHeap.push({entry.second, entry.first});
                if(minHeap.size() > k)
                {
                    minHeap.pop(); // removing the least freq. element.
                }
            }

            // At this point, my minHeap has top k freq.element.
            vector<int> ans;

            while(!minHeap.empty())
            {
                // pair<int, int> top = minHEap.top();
                // auto top = minHeap.top();
                auto [freq, num] = minHeap.top();
                minHeap.pop();
                ans.push_back(num);
            }
            return ans;
        }
};

int main()
{
    vector<int> nums {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution s1;
    vector<int> res = s1.topKFrequent(nums, k);

    for(auto i: res)
    {
        cout << i << " ";
    }
    // Input: nums = [1,1,1,2,2,3], k = 2
    // Output: [1,2]
    return 0;
}