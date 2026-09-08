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
        int getHeight(TreeNode* root)
        {
            if(root == NULL)
            {
                return 0;
            }
            int left = getHeight(root -> left);
            int right = getHeight(root -> right);
            int maxHeight = max(left, right);
            int totalHeight = maxHeight + 1;
            return totalHeight;
        }

        int diameterOfBinaryTree(TreeNode* root)
        {
            if(root == NULL)
            {
                return 0;
            }
            int option1 = diameterOfBinaryTree(root -> left);
            int option2 = diameterOfBinaryTree(root -> right);
            int option3 = getHeight(root -> left) + getHeight(root -> right);
            int maxDiameter = max(option1, max(option2, option3));

            return maxDiameter;
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