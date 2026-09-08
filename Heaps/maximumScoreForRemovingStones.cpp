#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    public:
        int maximumScore(int a, int b, int c)
        {
            //maxheap
            priority_queue<int, vector<int>> maxHeap;
            maxHeap.push(a);
            maxHeap.push(b);
            maxHeap.push(c);

            int score = 0;

            while(maxHeap.size() > 1)
            {
                int pile1 = maxHeap.top();
                maxHeap.pop();
                int pile2 = maxHeap.top();
                maxHeap.pop();

                pile1--, pile2--;
                score++;

                if(pile1 > 0)
                {
                    maxHeap.push(pile1);
                }
                if(pile2 > 0)
                {
                    maxHeap.push(pile2);
                }
            }
            return score;
        }
};

int main()
{
    int a = 2, b = 4, c = 6;
    Solution s1;
    int res = s1.maximumScore(a, b, c);
    cout << res;
    // Input: a = 2, b = 4, c = 6
    // Output: 6
    return 0;
}