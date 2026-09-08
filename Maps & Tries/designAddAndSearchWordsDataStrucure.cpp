#include <iostream>
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

    bool searchUtil(TrieNode *root, string &word, int i = 0)
    {
        if (i == word.size())
            return root->isTerminal;

        char ch = word[i];
        bool matched = false;
        if (ch == '.')
        {
            //. can be matched to any child of current root Trie node.
            // for(auto &[childChar, childNode]: root->children)
            //     matched = matched || searchUtil(root->children[childChar], word, i + 1);
            for (auto it : root->children)
                matched = matched || searchUtil(root->children[it.first], word, i + 1);
        }
        else
        {
            if (root->children.find(word[i]) != root->children.end())
                matched = searchUtil(root->children[word[i]], word, i + 1);
        }
        return matched;
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

class WordDictionary
{
    Trie trie;

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(word);
    }
};

int main() {
    WordDictionary dict;

    // Add words
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");

    // Basic exact searches
    cout << boolalpha;
    cout << "Search 'pad': " << dict.search("pad") << endl; // false
    cout << "Search 'bad': " << dict.search("bad") << endl; // true

    // Wildcard searches
    cout << "Search '.ad': " << dict.search(".ad") << endl; // true
    cout << "Search 'b..': " << dict.search("b..") << endl; // true
    cout << "Search '..d': " << dict.search("..d") << endl; // true
    cout << "Search '...': " << dict.search("...") << endl; // true
    cout << "Search '....': " << dict.search("....") << endl; // false

    return 0;
}
