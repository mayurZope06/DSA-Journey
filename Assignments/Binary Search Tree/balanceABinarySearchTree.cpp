#include <iostream>
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

class Solution
{
    public:

    void inorder(TreeNode* root, vector<int> &in)
    {
        if(!root)
        {
            return;
        }
        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }
    
    TreeNode* buildTree(vector<int> &in, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }

        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(in[mid]);

        root -> left = buildTree(in, start, mid - 1);
        root -> right = buildTree(in, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int> in;
        inorder(root, in);

        //build balanced BST using inorder traversal
        return buildTree(in, 0, in.size() - 1);
    }
};

// Helper function to print inorder traversal of BST
void printInorder(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    // Creating unbalanced BST [1, null, 2, null, 3, null, 4]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution obj;
    TreeNode* balancedRoot = obj.balanceBST(root);

    cout << "Inorder Traversal of Balanced BST: ";
    printInorder(balancedRoot);  // Output should be: 1 2 3 4
    cout << endl;

    return 0;
}