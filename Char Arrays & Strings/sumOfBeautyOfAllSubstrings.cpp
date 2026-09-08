#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
//#include <algorithm>
using namespace std;

class Solution
{
    public:
        int beautySum(string s)
        {
            int beautySum = 0;
            unordered_map<char, int> mp;

            //find all substrings
            for(int i = 0; i < s.size(); i++)
            {
                mp.clear();
                for (int j = i; j < s.size(); j++)
                {
                    char &ch = s[j];
                    mp[ch]++; // freq update of the char ch
                    int mini = INT_MAX;
                    int maxi = INT_MIN;

                    // find most & least frequent ch from the map
                    for (auto each : mp)
                    {
                        maxi = max(maxi, each.second);
                        mini = min(mini, each.second);
                    }
                    int beauty = maxi - mini;
                    beautySum += beauty;
                }
            }
            return beautySum;
        }
};
int main()
{
    string s = "aabcb";
    Solution s1;
    int res = s1.beautySum(s);
    cout << res;

    return 0;
}