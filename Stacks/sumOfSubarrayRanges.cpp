unique#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    public:
        vector<int> nextSmallerElement(vector<int> &v)
        {
            stack<int> st;
            st.push(-1);

            vector<int> ans(v.size(), -1);

            for(int i = v.size() - 1; i >= 0; i--)
            {
                while(!st.empty() && st.top() != -1 && v[st.top()] > v[i])
                {
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }

        vector<int> prevSmallerElement(vector<int> &v)
        {
            stack<int> st;
            st.push(-1);

            vector<int> ans(v.size(), -1);

            for(int i = 0; i < v.size(); i++)
            {
                while(!st.empty() && st.top() != -1 && v[st.top()] >= v[i])
                {
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }

        long long sumSubarrayMins(vector<int> &arr)
        {
            auto next = nextSmallerElement(arr);
            auto prev = prevSmallerElement(arr);
            long long sum = 0;

            for(int i =0; i < arr.size(); i++) 
            {
                long long nexti = next[i] == -1 ? arr.size() : next[i];
                long long previ = prev[i];
                long long left = i - previ;
                long long right = nexti - i;
                sum += left * right * arr[i];
            }
            return sum;
        }

        vector<int> nextGreaterElement(vector<int> &v)
        {
            stack<int> st;
            st.push(-1);

            vector<int> ans(v.size(), -1);

            for(int i = v.size() - 1; i >= 0; i--)
            {
                while(!st.empty() && st.top() != -1 && v[st.top()] < v[i])
                {
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }

        vector<int> prevGreaterElement(vector<int> &v)
        {
            stack<int> st;
            st.push(-1);

            vector<int> ans(v.size(), -1);

            for(int i = 0; i < v.size(); i++)
            {
                while(!st.empty() && st.top() != -1 && v[st.top()] <= v[i])
                {
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }

        long long sumSubarrayMaxs(vector<int> &arr)
        {
            auto next = nextGreaterElement(arr);
            auto prev = prevGreaterElement(arr);
            long long sum = 0;

            for(int i =0; i < arr.size(); i++) 
            {
                long long nexti = next[i] == -1 ? arr.size() : next[i];
                long long previ = prev[i];
                long long left = i - previ;
                long long right = nexti - i;
                sum += left * right * arr[i];
            }
            return sum;
        }

        long long subArrayRanges(vector<int> &nums)
        {
            auto sumOfMaximums = sumSubarrayMaxs(nums);
            auto sumOfMinimums = sumSubarrayMins(nums);
            return sumOfMaximums - sumOfMinimums; 
        }
};

int main()
{
    vector<int> nums {1, 2, 3};

    Solution s1;
    cout << s1.subArrayRanges(nums);

    return 0;
}