#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[58];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false)
    {
        for (int i = 0; i < 58; ++i)
            children[i] = 0;
    }
};

class Trie
{
    TrieNode* root;
    void insertUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
        {
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'A';
    
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);
    
        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
            return root->isTerminal;

        int index = word[i] - 'A';

        if (root->children[index])
            return searchUtil(root->children[index], word, i + 1);

        else if(islower(word[i]))
        {
            return searchUtil(root, word, i + 1);
        }
        return false;
    }

    public:
        
        Trie() 
        {
            root = new TrieNode('\0');
        }

        void insert(string &word) 
        {
            insertUtil(root, word, 0);
        }
        
        int search(string &word) 
        {
            return searchUtil(root, word, 0);
        }
};

class Solution {
    public:
        vector<bool> camelMatch(vector<string>& queries, string pattern) {
            vector<bool> ans;
            Trie trie;
            trie.insert(pattern);
            for(auto query:queries){
                ans.push_back(trie.search(query));
            }
            return ans;
        }
    };
    

    int main()
    {
        vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
        string pattern = "FB";
    
        Solution sol;
        vector<bool> result = sol.camelMatch(queries, pattern);
    
        cout << "Output: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << (result[i] ? "true" : "false");
            if (i != result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    
        return 0;
    }
    