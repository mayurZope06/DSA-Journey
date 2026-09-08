#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures)
        {
            vector<int> ans(temperatures.size(), 0);
            stack<int> st;

            for(int i = 0; i < temperatures.size(); ++i)
            {
                while(!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            return ans;
        }
};

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution s1;
    vector<int> res = s1.dailyTemperatures(temperatures);
    for(auto i: res)
    {
        cout << i << " ";
    }
    return 0;
}