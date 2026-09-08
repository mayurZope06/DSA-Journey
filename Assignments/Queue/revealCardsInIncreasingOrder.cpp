#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<int> deckRevealedIncreasing(vector<int> &deck)
        {
            sort(deck.begin(), deck.end());
            queue<int> q;
            vector<int> ans(deck.size());

            //put indices of ans into q
            for(int i = 0; i < ans.size(); i++)
            {
                q.push(i);
            }

            //reverse simulation + filling using sorted deck
            for(int i = 0; i < deck.size(); i++)
            {
                //1.Reveal
                ans[q.front()] = deck[i];
                q.pop();

                //2.push front to bottom
                if(!q.empty())
                {
                    auto f = q.front();
                    q.pop();
                    q.push(f);
                }
            }
            return ans;
        }
};

int main()
{
    vector<int> deck {17, 13, 11, 2, 3, 5, 7};
    Solution s1;
    vector<int> res = s1.deckRevealedIncreasing(deck);
    for(auto i: res)
    {
        cout << i << " ";
    }
    return 0;
}