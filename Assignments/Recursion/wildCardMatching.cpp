#include <iostream>
using namespace std;

class Solution
{
    public:
        bool isMatchHelper(string &s, int si, string &p, int pi)
        {
            //base
            if(si == s.size() && pi == p.size())
            {
                return true;
            }
            if(si == s.size() && pi < p.size())
            {
                while(pi < p.size())
                {
                    if(p[pi] != '*')
                    {
                        return false;
                    }
                    pi++;
                }
                return true;
            }

            //single char matching
            if(s[si] == p[pi] || '?' == p[pi])
            {
                return isMatchHelper(s, si + 1, p, pi + 1);
            }
            if(p[pi] == '*')
            {
                //treat '*' as empty or null
                bool caseA = isMatchHelper(s, si, p, pi + 1);

                //Let '*' consume one char
                bool caseB = isMatchHelper(s, si + 1, p, pi);

                return caseA || caseB;
            }

            //char doesn't match
            return false;
        }
        bool isMatch(string s, string p)
        {
            int si = 0; //pointer index for s string
            int pi = 0; //pointer index for p string
            return isMatchHelper(s, si, p, pi);
        }
};

int main()
{
    string s = "abcdefg";
    string p = "ab*fg";

    Solution s1;
    cout << s1.isMatch(s, p);
    return 0;
}