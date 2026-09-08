#include <iostream>
#include <vector>
#include <queue>
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
        TreeNode* solve(vector <int> &inorder, int s, int e)
        {
            if(s > e)
            {
                return NULL;
            }

            //1 case solve krdeta hu
            int mid = (s + e) / 2;
            int element = inorder[mid];
            TreeNode* root = new TreeNode(element);

            //baaki recursion sambhal lega
            root -> left = solve(inorder, s, mid - 1);
            root -> right = solve(inorder, mid + 1, e);
            return root;
        }
        TreeNode* sortedArrayToBST(vector<int> &inorder)
        {
            int s = 0;
            int n = inorder.size();
            int e = n - 1;
            TreeNode* root = solve(inorder, s, e);
            return root;
        }
};

// Level Order Traversal to verify the BST
void levelOrderTraversal(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        cout << endl; // For level separation
    }
}

int main()
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};

    // Create BST from sorted array
    TreeNode* root = sol.sortedArrayToBST(nums);

    // Print Level Order Traversal of BST
    cout << "Level Order Traversal of BST: " << endl;
    levelOrderTraversal(root);

    return 0;
}