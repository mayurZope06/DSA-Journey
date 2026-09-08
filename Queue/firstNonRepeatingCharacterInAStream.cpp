#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        string FirstNonRepating(string A)
        {
            unordered_map<char, int> freq;
            string ans = "";
            queue<int> q;

            for(int i = 0; i < A.length(); i++)
            {
                char ch = A[i];

                //Initial state maintain krne k liye 
                freq[ch]++;
                q.push(ch);

                //Let's find the answer now 
                while(!q.empty())
                {
                    char frontElement = q.front();

                    //check whether frontElement is answer or not
                    if(freq[frontElement] == 1)
                    {
                        ans.push_back(frontElement);
                        break;
                    }
                    else
                    {
                        //frontElement is duplicate element
                        q.pop();
                    }
                }
                //Important condition
                //agar sab duplicate element the, toh q empty hogi
                // agar koi bhi unique element h, toh q empty nahi hogi
                if(q.empty())
                {
                    ans.push_back('#');
                }
            }
            return ans;
        }
};

int main()
{
    Solution s1;
    string A = "aacdde";

    cout << s1.FirstNonRepating(A);
    return 0;
}