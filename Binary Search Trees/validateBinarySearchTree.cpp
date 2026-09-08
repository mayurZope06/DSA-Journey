#include <iostream>
#include <climits>
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
        bool validate(TreeNode*root, long long lb, long long ub)
        {
            if(!root)
            {
                return true;
            }

            bool isCurrentNodeInRange = root -> val > lb && root -> val < ub;
            bool isLeftBST = true;
            bool isRightBST = true;

            if(isCurrentNodeInRange)
            {
                isLeftBST = validate(root -> left, lb, root -> val);
                isRightBST = validate(root -> right, root -> val, ub);
            }

            return isCurrentNodeInRange && isLeftBST && isRightBST;
        }

        bool validate2(TreeNode*root, long long lb, long long ub)
        {
            if(!root)
            {
                return true;
            }

            return root -> val > lb && root -> val < ub && validate2(root -> left, lb, root -> val) && validate2(root -> right, root -> val, ub);
        }
        
        bool isValidBST(TreeNode* root) 
        {
            long long lb = LONG_MIN, ub = LONG_MAX;
            return validate2(root, lb, ub);
        }
};


// Helper function to create the BST
TreeNode* insert(TreeNode* root, int val)
{
    if(!root)
    {
        return new TreeNode(val);
    }
    
    if(val < root -> val)
    {
        root -> left = insert(root -> left, val);
    }
    else
    {
        root -> right = insert(root -> right, val);
    }
    return root;
}

int main()
{
    // Create the BST: [2, 1, 3]
    TreeNode* root = new TreeNode(2);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(3);

    // Create a solution object
    Solution sol;
    bool result = sol.isValidBST(root);

    // Print the result
    if(result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}