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
        bool solve(TreeNode* root, int target, int sum)
        {
            if(root == NULL)
            {
                return false;
            }

            //root palla not null h
            sum = sum + root -> val;
            if(root -> left == NULL && root -> right == NULL)
            {
                //root is a leaf node
                if(sum == target)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            bool leftAns = solve(root -> left, target, sum);
            bool rightAns = solve(root -> right, target, sum);
            return leftAns || rightAns;
            // if(leftAns == false && rightAns == false) {
            //     return false;
            // }
            // else if(leftAns == true && rightAns == false) {
            //     return true;
            // }
            // else if(leftAns == false && rightAns == true) {
            //     return true;
            // }
            // else {
            //     //leftAns == true && rightAns == true
            //     return true;
            // }
        }
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            int sum = 0;
            bool ans = solve(root, targetSum, sum);
            return ans;
        }
};

int main() {
    // Creating the tree: root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    Solution sol;
    
    if (sol.hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists." << endl;
    } else {
        cout << "No path with sum " << targetSum << " found." << endl;
    }

    return 0;
}
