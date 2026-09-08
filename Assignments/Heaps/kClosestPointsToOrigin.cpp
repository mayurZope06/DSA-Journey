#include <iostream>
#include <queue>
using namespace std;

class Solution
{
    public:
        class mycomp
        {
            public:
                bool operator() (pair<int, int> &a, pair<int, int> &b)
                {
                    int distA = a.first * a.first + a.second * a.second;
                    int distB = b.first * b.first + b.second * b.second;

                    return distA > distB;
                }
        };

        vector<vector<int>> kClosest(vector<vector<int>> &points,  int k)
        {
            vector<vector<int>> ans;

            priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> pq; // minHeap based on giving higher pq to point closer to origin
            for(auto p : points)
            {
                pq.push({p[0], p[1]});
            }
            while(!pq.empty() && k--)
            {
                auto &top = pq.top();
                ans.push_back({top.first, top.second});
                pq.pop();
            }
            return ans;
        }
};

int main()
{
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;

    Solution s1;
    vector<vector<int>> res = s1.kClosest(points, k);
    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}