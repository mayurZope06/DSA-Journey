#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<TreeNode*> ans;
        unordered_map<string, int> subTreeMap;
        string preorder(TreeNode* root) 
        {
            if (!root) return "N";
            
            string curr = to_string(root->val);
            string l = preorder(root->left);
            string r = preorder(root->right);
            string s = curr + "," + l + "," + r;
            if (subTreeMap.find(s) != subTreeMap.end()) 
            {
                if (subTreeMap[s] == 1)
                    ans.push_back(root);
                subTreeMap[s]++;
            } else {
                subTreeMap[s] = 1;
            }
            return s;
        }
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
        {
            preorder(root);
            return ans;
        }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    /*
    Tree structure:
                  1
                 / \
                2   3
               /   / \
              4   2   4
                 /
                4
    Expected Output: [[2,4],[4]]
    */

    // Constructing the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    Solution sol;
    vector<TreeNode*> duplicates = sol.findDuplicateSubtrees(root);

    // Printing duplicate subtree roots
    cout << "Duplicate Subtrees:\n";
    for (auto node : duplicates) {
        printTree(node);
        cout << endl;
    }

    return 0;
}