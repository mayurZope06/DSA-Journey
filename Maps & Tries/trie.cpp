#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode
{
    public:
        char value;
        unordered_map<int, TrieNode*> children;
        bool isTerminal;

        TrieNode(char data)
        {
            value = data;
            isTerminal = false;
        }
};

void insertIntoTrie (TrieNode* root, string word)
{
    //base case - ek time aisa ayega, jab aapki string empty aaegi
    if(word.length() == 0)
    {
        root -> isTerminal = true;
        return;
    }

    //1 case solve krna h
    // 1 character ko trie me insert krdeta hu
    char ch = word[0];
    TrieNode* child;

    //present h toh wha chale jao
    //absent h toh create kardo

    if(root -> children.count(ch) == 1)
    {
        child = root -> children[ch];
    }
    else
    {
        //absent 
        child = new TrieNode(ch);
        //link
        root -> children[ch] = child;
    }
    //baki recursion sambhal lega
    insertIntoTrie(child, word.substr(1));
}

bool searchTrie(TrieNode* root, string word)
{
    //base case
    //check last character terminal hai ya nahi
    if(word.length() == 0)
    {
        //iska mtlb root me last character pada hua h
        return root -> isTerminal;
    }
    
    //1 case main solve krunga
    char ch = word[0];
    TrieNode* child;

    if(root -> children.find(ch) != root -> children.end())
    {
        //present
        child = root -> children[ch];
    }
    else
    {
        //absent
        return false;
    }

    //baaki recursion
    bool recursionKsAns = searchTrie(child, word.substr(1));
    return recursionKsAns;
}

void deleteWord(TrieNode* root, string word)
{
    //base case
    //ek time aisa aaega, jab word empty hoga
    //and root me last last character hoga
    if(word.length() == 0)
    {
        root -> isTerminal = false;
        return;
    }
    // 1 case main solve karunga
    char ch = word[0];
    TrieNode* child;

    if(root -> children.find(ch) != root -> children.end())
    {
        //present
        child = root -> children[ch];
    }
    else
    {
        //absent 
        return;
    }
    //baaki recursion
    deleteWord(child, word.substr(1));
}

int main()
{
    TrieNode* root = new TrieNode('_');

    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "care");
    insertIntoTrie(root, "snake");
    insertIntoTrie(root, "fivefoot");
    insertIntoTrie(root, "extremelywell");
    insertIntoTrie(root, "coward");
    insertIntoTrie(root, "selfobsessed");
    insertIntoTrie(root, "tag");
    insertIntoTrie(root, "take");
    insertIntoTrie(root, "took");

    bool ans = searchTrie(root, "cover");
    if(ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    deleteWord(root, "cover");
    ans = searchTrie(root, "cover");
    if(ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    
    return 0;
}