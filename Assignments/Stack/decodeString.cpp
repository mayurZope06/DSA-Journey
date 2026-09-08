#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
    public:
        string decodeString(string s)
        {
            stack<string> st;

            for(auto ch: s)
            {
                if(ch == ']')
                {
                    string stringToRepeat = "";
                    while(!st.empty() && st.top() != "[")
                    {
                        string top = st.top();
                        stringToRepeat += top;
                        st.pop();
                    }
                    st.pop();

                    string numericTimes = "";
                    while(!st.empty() && isdigit(st.top()[0]))
                    {
                        numericTimes += st.top();
                        st.pop();
                    }

                    reverse(numericTimes.begin(), numericTimes.end());

                    int n = stoi(numericTimes);

                    //final decoding
                    string currentdecode = "";
                    while(n--)
                    {
                        currentdecode += stringToRepeat;
                    }
                    st.push(currentdecode);
                }
                else
                {
                    string temp(1, ch);
                    st.push(temp);
                }
            }
            string ans;
            while(!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

int main()
{
    string s = "3[a2[bc]]";

    Solution s1;
    cout << s1.decodeString(s);

    return 0;
}