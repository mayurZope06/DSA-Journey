#include <iostream>
using namespace std;
class Solution
{
    public:
        bool checkPalindrome (string str, int s, int e)
        {
            while (s <= e)
            {
                if (str[s] != str[e])
                {
                    return false;
                }
                else{
                    s++;
                    e--;
                }
            }
            return true;
        }
        bool validPalindrome(string s)
        {
            int len = s.length();
            int i = 0 ;
            int j = len - 1;

            while (i <= j)
            {
                if (s[i] == s[j])
                {
                    i++;
                    j--;
                }
                else{
                    bool ansOne = checkPalindrome(s, i+1, j);
                    bool ansTwo = checkPalindrome(s, i, j-1);
                    bool finalAns= ansOne || ansTwo;
                    return finalAns;
                }
            }
            return true;
        }
};
int main()
{
    // s = "abca";
    //string s = "RacacbR";
    string s = "abc";
    Solution s1;
    bool res = s1.validPalindrome(s);
    cout<<res;

    return 0;
}