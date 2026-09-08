#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
    public:
        vector<double> getCollisionTimes(vector<vector<int>>& cars) 
        {
            vector<double> answer(cars.size(), -1); // collision time of ith car with the next car.
            stack<int> st;
            
            for(int i = cars.size() - 1; i >= 0; --i)
            {
                // Check if the car ahead of the current car is faster?
                while(!st.empty() && cars[st.top()][1] >= cars[i][1]) 
                {
                    st.pop();
                }
    
                while(!st.empty()) 
                {
                    double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                    if(answer[st.top()] == -1 || colTime <= answer[st.top()]) 
                    {
                        answer[i] = colTime;
                        break;
                    }
                    st.pop();
                }
                
                st.push(i);
            }
            
            return answer;
        }
};

int main()
{
    vector<vector<int>> cars = {{3,4}, {5,4}, {6,3}, {9,1}};

    Solution s1;
    vector<double> res = s1.getCollisionTimes(cars);

    for(auto i: res)
    {
        cout << i << " ";
    }
    return 0;
}