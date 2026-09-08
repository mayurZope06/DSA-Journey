#include <iostream>
#include <algorithm>
using namespace std;
string orderCopy;
class Solution
{
    public:
        
        static bool cmp(char a, char b)
        {
            return (orderCopy.find(a) < orderCopy.find(b));
        }
        string customSortString (string order, string s)
        {
            orderCopy = order;
            sort (s.begin(), s.end(), cmp);
            return s;
        }
};
int main()
{
    string order = "cba";
    string s = "abcd";
    Solution s1;
    string result = s1.customSortString(order, s);
    cout<<result;
    return 0;
}