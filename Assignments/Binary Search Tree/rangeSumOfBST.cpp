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
        int rangeSumBST(TreeNode* root, int low, int high)
        {
            if(!root)
            {
                return 0;
            }
            int ans = 0;
            bool wasInRange = false;

            if(root -> val >= low && root-> val <= high)
            {
                wasInRange = true;
                ans += root -> val;
            }
            if(wasInRange)
            {
                ans += rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
            }
            else if(root -> val < low)
            {
                ans +=rangeSumBST(root -> right, low, high);
            }
            else if(root -> val > high)
            {
                ans += rangeSumBST(root -> left, low, high);
            }
            return ans;
        }
};

// Helper function to insert a node in BST
TreeNode* insert(TreeNode* root, int key)
{
    if (root == NULL)
    {
        return new TreeNode(key);
    }

    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

int main()
{
    // Create the BST
    TreeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    // Define the range
    int low = 7, high = 15;

    // Create a solution object and calculate the range sum
    Solution sol;
    int result = sol.rangeSumBST(root, low, high);

    // Print the result
    cout << "Output: " << result << endl;

    return 0;
}
