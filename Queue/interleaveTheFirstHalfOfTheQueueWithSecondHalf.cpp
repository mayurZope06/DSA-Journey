#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> rearrangeQueue(queue<int> &q1)
        {
            vector<int> ans;
            queue<int> q2;

            int n = q1.size();
            int half = n / 2;

            while(half--)
            {
                int element = q1.front();
                q1.pop();
                q2.push(element);
            }

            //first half -> q2
            //second half -> q1
            int size = q1.size();
            while(size--)
            {
                ans.push_back(q2.front());
                q2.pop();
                ans.push_back(q1.front());
                q1.pop();
            }
            return ans;
        }
};

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    Solution s1;
    vector<int> res = s1.rearrangeQueue(q);

    for(int i: res)
    {
        cout << i << " ";
    }
    return 0;
}