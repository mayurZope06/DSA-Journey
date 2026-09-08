 #include <iostream>
 #include <unordered_map>
 #include <vector>
 using namespace std;

 class Solution {
    public:
    void normalize(string &str) {
        char start = 'a';
        unordered_map<char, char> mapping;

        for(int i = 0; i < str.length(); i++) {
            char stringKaCharacter = str[i];

            if(mapping.find(stringKaCharacter) == mapping.end()) {
                mapping[stringKaCharacter] = start;
                start++;
            }
        }
        for(int i = 0; i < str.length(); i++) {
            char mappedChar = mapping[str[i]];
            str[i] = mappedChar;
        } 
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        normalize(pattern);

        for(int i = 0; i < words.size(); i++) {
            string currWord = words[i];
            normalize(currWord);
            if(currWord == pattern) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};

 int main()
 {
    return 0;
 }