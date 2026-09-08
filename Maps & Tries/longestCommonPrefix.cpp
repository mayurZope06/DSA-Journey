// // Logic: If only one child and not terminal, continue adding to answer
// void findLCP(TrieNode* root, string& ans) {
//     // Base case: stop if current node is terminal
//     if (root->isTerminal == true) {
//         return;
//     }

//     TrieNode* child;

//     // If exactly one child, continue exploring
//     if (root->children.size() == 1) {
//         // Get the only child
//         auto it = root->children.begin();
//         ans.push_back(it->first);
//         child = it->second;

//         // Recursive call
//         findLCP(child, ans);
//     } else {
//         // If more than one child or none, stop
//         return;
//     }
// }


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode{
    public: 
        char data;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;

        TrieNode(char val ) {
            data = val;
            isTerminal = false;
        }
};
void insertWord(TrieNode* root, string word) {
            //base case 
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            //1 case hum khud solve krenbge 
            char ch = word[0];
            TrieNode* child ;
            if(root->children.find(ch) != root->children.end()) {
                //present
                child = root->children[ch];
            }
            else {
                //absent
                child = new TrieNode(ch);
                root->children[ch] = child;
            }
            //baaki recursion
            insertWord(child, word.substr(1));
}

//logic -> single baccha, ans insert
void findlcp(TrieNode* root, string &ans) {
    //base case
    if(root->isTerminal == true) {
        return;
    }

    //1 case main solve krta hu
    TrieNode* child;
    if(root->children.size() == 1) {
        //1 hi baccha h
        for(auto i: root->children) {
            char ch = i.first;
            ans.push_back(ch);
            child = i.second;
        }
    }
    else {
        //multiple or 0 bacha h 
        return;
    }
    //baaki kon sambhalega 
    findlcp(child, ans);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        //insert all words into trie
        for(auto word : strs) {
            insertWord(root, word);
        }

        //main logic 
        string ans = "";
        findlcp(root,ans);
        return ans;   
    }
};

int main() {
    Solution s;
    vector<string> input = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << s.longestCommonPrefix(input) << endl;  // Output: "fl"

    vector<string> input2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << s.longestCommonPrefix(input2) << endl;  // Output: ""

    return 0;
}
