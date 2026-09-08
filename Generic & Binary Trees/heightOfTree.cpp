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
    public:SE
        int maxDepth(TreeNode* root)
        {
            //Base Case
            if(root == NULL)
            {
                return 0;
            }

            int leftSubtreeHeight = maxDepth(root -> left);
            int rightSubtreeHeight = maxDepth(root -> right);

            int maxHeight = max(leftSubtreeHeight, rightSubtreeHeight);
            int totoalHeight = maxHeight + 1;
            return totoalHeight;
        }
};

int main()
{
    // Constructing the tree:  [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Depth of the Tree: " << sol.maxDepth(root) << endl;

    // Freeing allocated memory
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}