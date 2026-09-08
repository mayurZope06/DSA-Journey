#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    TreeNode*FV = 0, *SV = 0, *prev = 0;
public:
    void solve(TreeNode*curr)
    {
        if(!curr) return;

        solve(curr->left);

        // store & compute
        if(prev && curr->val < prev->val)
        {
            // property is violated
            if(!FV) FV = prev;
            SV = curr;
        }

        prev = curr;

        solve(curr->right);
    }

    void recoverTree(TreeNode* root) 
    {
        solve(root);
        if(FV && SV)
            swap(FV->val, SV->val);
    }
};

// Helper function to create a BST
TreeNode* insert(TreeNode* root, int val) {
    if(!root)
        return new TreeNode(val);
    
    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Helper function to print inorder traversal of the BST
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    // Manually create the BST: [1, 3, null, null, 2] with swapped nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    cout << "Original BST (with swapped nodes): ";
    inorder(root);
    cout << endl;

    // Create a solution object and fix the tree
    Solution sol;
    sol.recoverTree(root);

    // Print the corrected BST
    cout << "Corrected BST: ";
    inorder(root);
    cout << endl;

    return 0;
}