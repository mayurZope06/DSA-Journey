#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            priority_queue<pair<int, int>> pq; // {val, index}
            vector<int> ans;
    
            // consider first window.
            for (int i = 0; i < k; ++i) {
                pq.push({nums[i], i});
            }
            // store max of first window
            ans.push_back(pq.top().first);
    
            // cosider rest of the windows.
            for (int i = k; i < nums.size(); ++i) {
                pq.push({nums[i], i});
    
                // remove if maxs are from previous windows.
                while (pq.top().second <= i - k) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
            return ans;
        }
    };

    int main() {
        vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
    
        Solution obj;
        vector<int> result = obj.maxSlidingWindow(nums, k);
    
        cout << "Output: [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    
        return 0;
    }