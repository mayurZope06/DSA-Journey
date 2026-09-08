#include <iostream>
//#include <map>
#include <unordered_map>
using namespace std;
class Solution
{
    public:
        string decodeMessage (string key, string message)
        {
            //Step 1: create mapping
            unordered_map<char, char>mapping;
            char space = ' ';
            mapping[space] = space;
            char start = 'a';
            char index = 0;

            while (start <= 'z' && index < key.length())
            {
                char keyKaCurrCharacter = key[index];
                
                if (mapping.find(keyKaCurrCharacter) != mapping.end())
                {
                    index++;
                }
                else{
                    mapping [keyKaCurrCharacter] = start;
                    start++;
                    index++;
                }
            }
            // step 2: use mapping and decode the message
            string ans = "";
            for (int i = 0; i < message.length(); i++)
            {
                char msgCharacter = message[i];
                char mappedCharacter = mapping[msgCharacter];
                ans.push_back(mappedCharacter);
            }
            return ans;
        }
};
int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    Solution s;
    string result = s.decodeMessage(key, message);
    cout<<result;
    return 0;
}