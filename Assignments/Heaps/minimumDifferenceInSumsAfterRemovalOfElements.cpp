#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    public:
    #define ll long long

    void print(vector<ll>&v){
        for(auto& i:v)
            cout << i << " ";
        cout << endl;
    }
    
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
        //prefix[i] = sum of first n elements from Left side.
        //suffix[i] = sum of first n elements from right side.
    
        ll sum = 0; // min n elements sum
        priority_queue<ll> pq; // max heap
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            pq.push(nums[i]);
    
            // pop out max elements
            if(pq.size() > n){
                sum -= pq.top();
                pq.pop();
            }
    
            if(pq.size() == n){
                prefix[i] = sum;
            }
        }
    
        sum = 0; // max n elements sum
        priority_queue<ll, vector<ll>, greater<ll>> pq2; // min heap
        for(int i = nums.size() - 1; i >= 0; --i){
            sum += nums[i];
            pq2.push(nums[i]);
    
            // pop out min elements
            if(pq2.size() > n){
                sum -= pq2.top();
                pq2.pop();
            }
    
            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }
    
        // print(prefix);
        // print(suffix);
        ll ans = LLONG_MAX;
        for(int i = n - 1; i < 2 * n; ++i){
            ans = min(ans, prefix[i] - suffix[i + 1]);
        }
    
        return ans;
    }
    
};

int main()
{
    vector<int> nums = {3, 1, 2};  // example input
    Solution sol;
    long long result = sol.minimumDifference(nums);
    cout << "Output: " << result << endl;
    return 0;
}