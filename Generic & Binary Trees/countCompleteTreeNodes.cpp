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
        int findLeftHeight(TreeNode*root)
        {
            int count = 0;
            while(root)
            {
                count++;
                root=root->left;
            }
            return count;
        }
    
        int findRightHeight(TreeNode*root)
        { // O(logn)
            int count = 0;
            while(root)
            {
                count++;
                root=root->right;
            }
            return count;
        }
    
        int countNodes(TreeNode* root) 
        {
            if(!root) return 0;
    
            int lh = findLeftHeight(root);
            int rh = findRightHeight(root);
    
            if(lh == rh) return (1 << lh) - 1; // 2^lh - 1
    
            // if lh != rh,
            // ans = 1 + (...) + (...)
            int lans = countNodes(root->left);
            int rans = countNodes(root->right);
            return 1 + lans + rans;
        }
};

int main()
{
    /*
    Tree structure:
                1
              /   \
             2     3
            / \   /
           4   5 6
    */
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int result = sol.countNodes(root);
    cout << "Total number of nodes in the tree: " << result << endl;

    return 0;
}