#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> seqCount; // stores 10 sized window substring
        vector<string> ans;

        if (s.size() < 10)
            return {};

        // slide the 10 size window
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string current10SizeWindowSubString = s.substr(i, 10);
            seqCount[current10SizeWindowSubString]++;
        }

        // for(auto it:seqCount){
        //     if(it.second > 1)
        //         ans.push_back(it.first);
        // }

        // seqCount : {string, int}
        // for (auto &[subStr, freq] : seqCount)
        // {
        //     if (freq > 1)
        //         ans.push_back(subStr);
        // }
        // return ans;
        for (auto &it : seqCount)
        {
            if (it.second > 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution s1;
    vector<string> res = s1.findRepeatedDnaSequences(s);
    for(auto i: res)
    {
        cout << i << " ";
    }
    return 0;
}