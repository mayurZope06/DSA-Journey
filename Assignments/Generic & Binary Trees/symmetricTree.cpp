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
    public:
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return true;
        }
        if(p && q)
        {
            return (p -> val == q -> val) && isMirror(p -> left, q-> right) && isMirror(p -> right, q -> left);
        }
        return false;
    }
    bool isSymmetric (TreeNode* root)
    {
        return isMirror(root -> left, root -> right);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    if(sol.isSymmetric(root))
    {
        cout << "The tree is symmetric." << endl;
    }
    else
    {
        cout << "The tree is not symmetric." << endl;
    }
    return 0;
}