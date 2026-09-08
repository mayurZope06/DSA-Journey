#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
    int maxMeetings(vector<int> start, vector<int> end) {
       
        vector<pair<int,int> > time;
        for(int i=0; i<start.size(); i++) {
            time.push_back({start[i], end[i]});
        }
        
        sort(time.begin(), time.end(), cmp);
        //sort basis on ending time 
        
        //main ye guranatee se keh skta hu k sabse pehli meeting toh mnain pkka include krunga 
        int count = 1;
        int prevStart = time[0].first;
        int prevEnd = time[0].second;
        
        for(int i=1; i<start.size(); i++) {
            int currStart = time[i].first;
            int currEnd = time[i].second;
            if(currStart > prevEnd) {
                //include kr skta hu 
                count++;
                //shifting 
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution s1;
    cout << s1.maxMeetings(start, end);
    return 0;
}