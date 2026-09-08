#include <iostream>
using namespace std;
class Solution
{
    public:
        string removeOccurrences (string full, string pattern)
        {
            while (full.find(pattern) != string::npos)
            {
                full.erase(full.find(pattern), pattern.length());
            }
            return full;
        }
};
int main()
{
    string full = "daabcbaabcbc";
    string pattern = "abc";
    Solution s1;
    string res = s1.removeOccurrences(full, pattern);
    cout<<res;

    return 0;
}