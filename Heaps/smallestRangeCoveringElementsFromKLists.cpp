#include <iostream>
#include <queue>
#include <climits>
using namespace std;


class Info{
    public:
        int data;
        int rIndex;
        int cIndex;
        Info(int a, int b, int c) {
            data = a;
            rIndex = b;
            cIndex = c;
        }
};

class compare{
    public:
        bool operator()(Info* a, Info* b) {
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;

        vector<int> ans;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        //process first k element
        int totalRows = nums.size();
        //i/nt totalColumns = nums[0].size();

        for(int row=0; row<totalRows; row++) {
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        //ans_start and ans_end stores the smallest diff wali values
        int ans_start = mini;
        int ans_end = maxi;

        ///main logic 
        while(!pq.empty()) {
            //front nikao 
            Info* front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;

            //ye bhul jata hu
            mini = frontData;

            //ans update
            if((maxi-mini) < (ans_end-ans_start)) {
                //found a new and small diff
                ans_start = mini;
                ans_end = maxi;
            }

            //aage lement h toh insert karo
            int currTotalColumns = nums[front_rIndex].size(); 

            if(front_cIndex + 1 < currTotalColumns) {
                int element = nums[front_rIndex][front_cIndex+1];
                Info* temp = new Info(element, front_rIndex, front_cIndex+1);
                maxi = max(maxi, element);
                pq.push(temp);
            }
            else {
                break;
            }

        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};

int main() {
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    Solution sol;
    vector<int> result = sol.smallestRange(nums);

    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}