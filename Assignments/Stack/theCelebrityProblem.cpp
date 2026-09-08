#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    public: 
        //Function to find if there is a celebrity in the party or not.
        int celebrity(vector<vector<int>> &M, int n)
        {
            stack <int> st;

            //step 1: push all persons into stack
            for(int i = 0; i < n; ++i)
            {
                st.push(i);
            }

            //step 2: run discard method to get a mightBeCelebrity
            while (st.size() != 1)
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                //if a knows b ?
                if(M[a][b])
                {
                    //a is not celebrity, b might be
                    st.push(b);
                }
                else
                {
                    //b is not celebrity, a might be
                    st.push(a);
                }
            }

            //step 3: check that single person is actually celebrity?
            int mightBeCelebrity = st.top(); st.pop();

            //celebrity should not know any one
            for(int i = 0; i < n; i++)
            {
                if(M[mightBeCelebrity][i] != 0)
                    return -1;
            }

            //everyone should know celebrity
            for (int i = 0; i < n; ++i)
            {
                if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity)
                    return -1;
            }

            //mightBeCelebrity is the celebrity.
            return mightBeCelebrity;
        }
};

int main()
{
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = 3;

    Solution s1;
    cout << s1.celebrity(M, n);
    return 0;
}