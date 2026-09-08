#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

class Solution
{
    public:
        string reverseString(string s)
        {
            reverse(s.begin(), s.end());
            int n = s.size();

            int start = 0, end = 0;

            for(int i = 0; i < n; i++)
            {
                //skip leading spaces
                while(i < n && s[i] == ' ')
                    i++;
                
                if (i == n ) break; // out of bound check

                // copy char to the right position
                while(i < n && s[i] != ' ')
                    s[end++] = s[i++];
                
                //after copy revrse the individual word
                reverse(s.begin() + start, s.begin() + end);

                //add extra space between word
                s[end++] = ' ';
                start = end;
            }
            //resize the final string
            s.resize(end - 1);
            return s;
        }
};
int main()
{
    string s = "  hello world  ";
    Solution s1;
    string res = s1.reverseString(s);
    cout << res;
    return 0;
}