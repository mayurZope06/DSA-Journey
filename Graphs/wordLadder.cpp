#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       queue< pair<string, int> > q;
       q.push({beginWord, 1});

       unordered_set<string> st(wordList.begin(), wordList.end());
       //kyoki main beginWord use kr chuka hu, queue me 
       ///toh i should erase it from dictionaqry or set
       st.erase(beginWord);

       //main traversal logic 

       while(!q.empty()) {
            pair<string,int> frontPair = q.front();
            q.pop();

            string frontString = frontPair.first;
            int frontDistance = frontPair.second;

            //check if front ki node is the endWord or not 
            if(frontString == endWord) {
                return frontDistance;
            }
            else {
                //toh ab change krne chalte h 
                for(int index=0; index < frontString.length(); index++) {
                    //why ?
                    char originalCharacter = frontString[index];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        frontString[index] = ch;
                        //check if the new string is there in the dictionary or not 
                        if(st.find(frontString) != st.end()) {
                            //valid string
                            q.push({frontString, frontDistance+1});
                            st.erase(frontString);
                        }
                    }
                    //backtrack
                    frontString[index] = originalCharacter;
                }
            }
           
       }

 return 0;


    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution obj;
    int result = obj.ladderLength(beginWord, endWord, wordList);

    cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
