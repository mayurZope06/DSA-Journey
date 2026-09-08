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

class Solution {
    public:
        int ans = 0;
        
        void pathFromOneRoot(TreeNode* root, long long sum) {
            if(!root) return;
    
            if(sum == root->val) {
                ++ans;
            }
    
            pathFromOneRoot(root->left, sum - root->val);
            pathFromOneRoot(root->right, sum - root->val);
        }
    
        int pathSum(TreeNode* root, long long targetSum) {
            if(root) {
                pathFromOneRoot(root, targetSum);
                pathSum(root->left, targetSum);
                pathSum(root->right, targetSum);
            }
    
            return ans;
        }
};
    

int main()
{
    // Creating the tree:
    //         10
    //        /  \
    //       5   -3
    //      / \    \
    //     3   2   11
    //    / \   \
    //   3  -2   1
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    long long targetSum = 8;
    
    Solution sol;
    int result = sol.pathSum(root, targetSum);

    // Print the number of paths
    cout << "Number of paths with sum " << targetSum << " is: " << result << endl;

    return 0;
}