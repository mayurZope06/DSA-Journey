#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string, vector<string> > map;
    
            for(int i=0; i<strs.size(); i++) 
            {
                string original = strs[i];
    
                string copy = strs[i];
                sort(copy.begin(), copy.end());
    
                map[copy].push_back(original);
            }
    
            vector<vector<string> > ans;
            for(auto i: map) 
            {
                ans.push_back(i.second);
            }
            return ans;
        }
};

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s1;
    vector<vector<string>> res = s1.groupAnagrams(strs);

    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}