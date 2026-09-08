#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    char data;
    unordered_map<char, TrieNode *> children;
    bool isTerminal;
    TrieNode(char ch) : data(ch), isTerminal(false) {}
};

class Trie
{
    TrieNode *root;
    void insertUtil(TrieNode *root, string &word, int i = 0)
    {
        if (i == word.size())
        {
            root->isTerminal = true;
            return;
        }

        if (root->children.find(word[i]) == root->children.end())
            root->children[word[i]] = new TrieNode(word[i]);
        insertUtil(root->children[word[i]], word, i + 1);
    }

    bool searchUtil(TrieNode *root, string &word, int i = 0, bool mismatch = false)
    {
        if (i == word.size())
            return mismatch && root->isTerminal;

        auto ch = word[i];
        if (root->children.find(ch) != root->children.end())
        {
            // match till you can
            if (searchUtil(root->children[ch], word, i + 1, mismatch))
                return true;
        }

        // if you are here means, there is a mismatch
        if (!mismatch)
        {
            // for (auto &[childChar, childNode] : root->children)
            // {
            //     if (ch != childChar && searchUtil(childNode, word, i + 1, true))
            //         return true;
            // }.
            for (auto &it : root->children)
            {
                if (ch != it.first && searchUtil(it.second, word, i + 1, true))
                    return true;
            }
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
        insertUtil(root, word);
    }

    bool search(string &word)
    {
        return searchUtil(root, word);
    }
};

class MagicDictionary
{
    Trie trie;

public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        for (auto &word : dictionary)
            trie.insert(word);
    }

    bool search(string searchWord)
    {
        return trie.search(searchWord);
    }
};

int main()
{
    MagicDictionary dict;

    vector<string> dictionary = {"hello", "hallo", "leetcode", "judge"};
    dict.buildDict(dictionary);

    cout << boolalpha;
    cout << "Search 'hello': " << dict.search("hello") << endl;      // false (no modification)
    cout << "Search 'hhllo': " << dict.search("hhllo") << endl;      // true ("hallo")
    cout << "Search 'hell': " << dict.search("hell") << endl;        // false (length mismatch)
    cout << "Search 'leetcodd': " << dict.search("leetcodd") << endl; // false
    cout << "Search 'judge': " << dict.search("judge") << endl;      // false (no modification)
    cout << "Search 'jedge': " << dict.search("jedge") << endl;      // true ("judge")

    return 0;
}
