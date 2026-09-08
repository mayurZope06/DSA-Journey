#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class comp{
    public:
        bool operator()(const pair<int, string>& a, const pair<int, string>& b){
            return a.first == b.first ? a < b : a.first > b.first;
        }
    };
    
    class TrieNode
    {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        int freq;
    
        TrieNode(char ch) : data(ch), isTerminal(false)
        {
            for (int i = 0; i < 26; ++i)
                children[i] = 0;
            freq = 0;
        }
    };

class Trie
{
    public:
        TrieNode* root;
        void insertUtil(TrieNode *root, string &word, int i)
        {
            if (i >= word.size())
            {
                root->isTerminal = true;
                ++root->freq;
                return;
            }

            int index = word[i] - 'a';

            if (!root->children[index])
                root->children[index] = new TrieNode(word[i]);

            insertUtil(root->children[index], word, i + 1);
        }

        void traverseUtil(TrieNode* root, string &s, priority_queue<pair<int,string>, vector<pair<int,string>>, comp> &pq, int &k) {
            if (!root) {
                return;
            }
        
            if (root->isTerminal) {
                // cout << "<" << root->freq << endl;
                // stores top k frequent words
                if (pq.size() < k) {
                    pq.push({root->freq, s});
                }
                else if (pq.size() == k && root->freq > pq.top().first) {
                    pq.pop();
                    pq.push({root->freq, s});
                }
            }
        
            for (int i = 0; i < 26; ++i) {
                if (root->children[i]) {
                    s.push_back(i + 'a');
                    traverseUtil(root->children[i], s, pq, k);
                    s.pop_back(); // backtracking
                }
            }
        }
        
    public:
        Trie()
        {
            root = new TrieNode('\0');
        }

        void insert(string word)
        {
            insertUtil(root, word, 0);
        }

        void traverse(priority_queue<pair<int,string>, vector<pair<int,string>>, comp> &pq, int &k)
        {
            string s;
            traverseUtil(root, s, pq, k);
        }
};

class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            Trie trie;
            vector<string> ans;
    
            for (auto word : words) {
                trie.insert(word);
            }
    
            priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
            trie.traverse(pq, k);
    
            while (!pq.empty()) {
                auto top = pq.top(); pq.pop();
                // cout << top.first << " " << top.second << endl;
                ans.push_back(top.second);
            }
    
            reverse(ans.begin(), ans.end());
            return ans;
        }
};
  
int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution sol;
    vector<string> result = sol.topKFrequent(words, k);

    cout << "Top " << k << " frequent words are:" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}