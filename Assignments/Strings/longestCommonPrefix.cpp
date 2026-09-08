#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;

        while(true) {
            char currCh = 0;
            for(auto str: strs) {
                if(i >= str.size()) {
                    //out of bound
                    currCh = 0;
                    break;
                }

                //just started
                if(currCh == 0) {
                    currCh = str[i];
                }
                else if(str[i] != currCh) {
                    currCh = 0;
                    break;
                }
            }
            if(currCh == 0) {
                break;
            }
            ans.push_back(currCh);
            i++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}