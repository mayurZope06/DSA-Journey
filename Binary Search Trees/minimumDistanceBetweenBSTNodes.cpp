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
        void solve(TreeNode* root, int &ans, TreeNode* &prev)
        {
            //inorder
            if(!root)
            {
                return;
            }
            solve(root -> left, ans, prev);

            //kuch kuch krna hai
            if(prev)
            {
                ans = min(ans, root -> val - prev -> val);
            }

            //update the prev
            prev = root;

            solve(root -> right, ans, prev);
        }
        int minDiffInBST(TreeNode* root)
        {
            TreeNode* prev = nullptr;
            int ans = INT_MAX; // minDiff
            solve(root, ans, prev);
            return ans;
        }
};

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
    // Create the BST: [4, 2, 6, 1, 3]
    TreeNode* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);

    // Create a solution object and get the minimum difference
    Solution sol;
    int result = sol.minDiffInBST(root);

    // Print the result
    cout << "Minimum difference in BST: " << result << endl;

    return 0;
}