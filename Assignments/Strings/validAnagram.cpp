#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256] = {0};

        for(int i = 0; i < s.length(); i++) {
            freqTable[s[i]]++;
        } // O(n)

        for(int i = 0; i < t.length(); i++) {
            freqTable[t[i]]--;
        } // O(m)

        for(int i = 0; i < 256; i++) {
            if(freqTable[i] != 0) {
                return false;
            }
        }
            //O(256)
        return true;
    }
};

int main()
{
    return 0;
}