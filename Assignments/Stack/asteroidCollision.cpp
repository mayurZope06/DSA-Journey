#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> asteroidCollision (vector<int> &asteroids)
        {
            stack<int> st;

            for(auto ast: asteroids)
            {
                bool destroy = false; // initially nothing is destroyed
                if(ast > 0)
                {
                    st.push(ast);
                }
                else
                {
                    // -ve ast
                    if(st.empty() || st.top() < 0)
                    {
                        st.push(ast);
                    }
                    else
                    {
                        //collision
                        while(!st.empty() && st.top() > 0)
                        {
                            if(abs(ast) == st.top())
                            {
                                destroy = true;
                                st.pop();
                                break;
                            }
                            else if(abs(ast) > st.top())
                            {
                                st.pop();
                            }
                            else
                            {
                                destroy = true;
                                break;
                            }
                        }
                        if(!destroy)
                        {
                            st.push(ast);
                        }
                    }
                }
            }
            vector<int> ans(st.size());
            for(int i = st.size() - 1; i >= 0; i--)
            {
                ans[i] = st.top();
                st.pop();
            }
            return ans;
        }
};

int main()
{
    vector<int> asteroids = {5, 10, -5};
    Solution s1;

    vector<int> res = s1.asteroidCollision(asteroids);
    for(auto i: res)
    {
        cout << i << " "; 
    }
    return 0;
}