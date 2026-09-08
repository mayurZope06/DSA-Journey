#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            //base cases
            if(root == NULL)
            {
                return NULL;
            }
            if(root -> val == p -> val)
            {
                return p;
            }
            if(root -> val == q -> val)
            {
                return q;
            }
            TreeNode* leftAns = lowestCommonAncestor(root -> left, p, q);
            TreeNode* rightAns = lowestCommonAncestor(root -> right, p, q);

            if(leftAns == NULL && rightAns == NULL)
            {
                return NULL;
            }
            else if(leftAns == NULL && rightAns != NULL)
            {
                return rightAns;
            }
            else if(leftAns != NULL && rightAns == NULL)
            {
                return leftAns;
            }
            else
            {
                //leftAns != NULL && rightAns != NULL
                //ans -> root Node
                return root;
            }
        }
};

TreeNode* buildTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main()
{
    TreeNode* root = buildTree();
    TreeNode* p = root->left;  // Node 5
    TreeNode* q = root->left->right->right;  // Node 4
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->val << endl;
    return 0;
}
