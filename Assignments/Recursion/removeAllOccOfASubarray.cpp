#include <iostream>
using namespace std;

class Solution
{
    public:
        void removeOccRE(string &s, string &part)
        {
            int found = s.find(part);
            if(found != string :: npos) // npos -> no position
            {
                //part string has been loacted 
                //please remove it
                string leftPart = s.substr(0, found);
                string rightPart = s.substr(found + part.size(), s.size());
                s = leftPart + rightPart;

                removeOccRE(s, part);
            }
            else
            {
                //base case
                //all occurences of part has been removed form s
                return;
            }
        }
        string removeOccurrences (string s, string part)
        {
            removeOccRE(s, part);
            return s;
        }
};

int main()
{
    string s = "daabcbaabcbc", part = "abc";

    Solution s1;
    string res = s1.removeOccurrences(s, part);
    cout << res;
    return 0;
}