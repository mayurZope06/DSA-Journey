// #include <iostream>
// using namespace std;
// // OPTIMISED WAY ->
// void insertWord(TrieNode* root, string word, int i = 0) {
//     // Base case
//     if (i >= word.size()) {
//         root->isTerminal = true;
//         return;
//     }

//     // Step where we solve ourselves
//     char ch = word[i];
//     TrieNode* child;

//     // Check if character is already present
//     if (root->children.find(ch) != root->children.end()) {
//         // Present
//         child = root->children[ch];
//     } else {
//         // Absent: create a new TrieNode
//         child = new TrieNode(ch);
//         root->children[ch] = child;
//     }

//     // Recursive call
//     insertWord(child, word, i + 1);
// }

// bool searchWord(TrieNode* root, string word, int i = 0) {
//     // Base case
//     if (i >= word.size()) {
//         return root->isTerminal;
//     }

//     // Solve current character
//     char ch = word[i];
//     TrieNode* child;

//     if (root->children.find(ch) != root->children.end()) {
//         // Character is present
//         child = root->children[ch];
//     } else {
//         // Character not found
//         return false;
//     }

//     // Recursive call for next character
//     bool recKaAns = searchWord(child, word, i + 1);
//     return recKaAns;
// }

// bool searchPrefix(TrieNode* root, string& word, int i = 0) {
//     // Base case: all characters in the prefix have been found
//     if (i >= word.size()) {
//         return true;
//     }

//     // Solve current character
//     char ch = word[i];
//     TrieNode* child;

//     if (root->children.find(ch) != root->children.end()) {
//         // Present
//         child = root->children[ch];
//     } else {
//         // Absent
//         return false;
//     }

//     // Recursive call for next character
//     bool recKaAns = searchPrefix(child, word, i + 1);
//     return recKaAns;
// }

// class Trie {
//     public:
//         TrieNode* root;
    
//         // Constructor
//         Trie() {
//             root = new TrieNode('-'); // '-' denotes dummy root character
//         }
    
//         // Insert a word
//         void insert(string word) {
//             insertWord(root, word);
//         }
    
//         // Search for a complete word
//         bool search(string word) {
//             bool ans = searchWord(root, word);
//             return ans;
//         }
    
//         // Check if any word starts with the given prefix
//         bool startsWith(string prefix) {
//             bool ans = searchPrefix(root, prefix);
//             return ans;
//         }
//     };
    

// int main()
// {
//     return 0;
// }


#include <iostream>
#include <unordered_map>
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

bool searchWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        return root->isTerminal;
    }

    //1 case solve krdeta hu 
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        //absent
        return false;
    }
    //baaki recursion dekhlega
    bool recKaAns = searchWord(child, word.substr(1));
    return recKaAns;
}

bool searchPrefix(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        return true;
    }

    //1 case solve krdeta hu 
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        //absent
        return false;
    }
    //baaki recursion dekhlega
    bool recKaAns = searchPrefix(child, word.substr(1));
    return recKaAns;
}


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }

    void insert(string word) {
       insertWord(root, word);
    }
    
    bool search(string word) {
        bool ans = searchWord(root, word);
        return ans;
    }
    
    bool startsWith(string prefix) {
        bool ans = searchPrefix(root, prefix);
        return ans;
    }
};

int main() {
    Trie* t = new Trie();

    t->insert("apple");
    t->insert("app");
    
    cout << "Search 'apple': " << t->search("apple") << endl;     // true
    cout << "Search 'app': " << t->search("app") << endl;         // true
    cout << "Prefix 'ap': " << t->startsWith("ap") << endl;       // true
    cout << "Search 'appl': " << t->search("appl") << endl;       // false
    cout << "Prefix 'b': " << t->startsWith("b") << endl;         // false

    return 0;
}
