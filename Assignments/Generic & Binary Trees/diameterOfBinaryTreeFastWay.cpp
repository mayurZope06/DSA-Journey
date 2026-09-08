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
    int D = 0;
        int height(TreeNode* root)
        {
            if(!root )
            {
                return 0;
            }
            int lh = height(root -> left);
            int rh = height(root -> right);

            //diameter
            int currD = lh + rh;
            D = max(D, currD);
            return max(lh, rh) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root)
        {
            height(root);
            return D;
        }
};

int main()
{
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);
    root->left->left->left = new TreeNode(80);
    root->left->right->right = new TreeNode(90);
    root->right->right->right = new TreeNode(95);

    Solution sol;
    cout << "Diameter of the Tree: " << sol.diameterOfBinaryTree(root) << endl;

    
    return 0;
}