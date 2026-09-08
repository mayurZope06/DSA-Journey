#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        string removeKdigits(string num, int k)
        {    string ans;
            stack<char> st;

            for(auto digit: num)
            {
                if(k > 0)
                {
                    while (!st.empty() && st.top() > digit)
                    {
                        st.pop();
                        k--;
                        if(k == 0)
                        {
                            break;
                        }
                    }
                    
                }
                st.push(digit);
            }
            if(k > 0)
            {
                while(!st.empty() && k)
                {
                    st.pop();
                    k--;
                }
            }
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }

            //removing leading zeros
            while(ans.size() > 0 && ans.back() == '0')
            {
                ans.pop_back();
            }

            //get real ans
            reverse(ans.begin(), ans.end());

            return ans == "" ? "0" : ans;
        }
};

int main()
{
    string num = "2561305";
    int k = 4;
    Solution s1;
    cout << s1.removeKdigits(num, k); 
    return 0;
}