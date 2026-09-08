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
        bool isbalanced = true;

        int height (TreeNode* root)
        {
            if(!root)
            {
                return 0;
            }

            int lh = height(root -> left);
            int rh = height(root -> right);

            //check for current node is it balanced ?
            if(isbalanced && (lh - rh) > 1)
            {
                isbalanced = false;
            }

            return max(lh, rh) + 1;
        }
        bool isBalanced(TreeNode* root)
        {
            height(root);
            return isbalanced;
        }
};

int main()
{
    // Creating the tree [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}