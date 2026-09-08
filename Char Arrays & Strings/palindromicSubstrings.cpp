#include <iostream>
using namespace std;
class Solution
{
    public:
        int expandAroundCenter (string s, int i, int j)
        {
            int count = 0;
            while (i >= 0 && j < s.length() && s[i] == s[j])
            {
                count++;
                i--;
                j++;
            }
            return count;
        }
        int countSubStrings(string s)
        {
            int totalCount = 0;
            for (int center = 0; center < s.length(); center++)
            {
                // odd
                int i = center;
                int j = center;
                int oddPalSubStringKaCount = expandAroundCenter(s, i, j);
                // evem
                i = center;
                j = center + 1;
                int evenPalSUbStrinKaCount = expandAroundCenter(s, i, j);
                totalCount = totalCount + oddPalSubStringKaCount + evenPalSUbStrinKaCount;

            }
            return totalCount;
        }
};
int main()
{
    string s = "abc";
    //string s = "aaa";
    Solution s1;
    int res = s1.countSubStrings(s);
    cout<<res;

    return 0;
}