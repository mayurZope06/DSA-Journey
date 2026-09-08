#include <iostream>
#include <climits>
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
        TreeNode* build(int &i, int min, int max, vector<int> &preorder)
        {
            if(i >= preorder.size())
            {
                return nullptr;
            }

            TreeNode* root = nullptr;
            if(preorder[i] > min && preorder[i] < max)
            {
                root = new TreeNode(preorder[i++]);
                root -> left = build(i, min, root -> val, preorder);
                root -> right = build(i, root -> val, max, preorder);
            }
            return root;
        }

        TreeNode* bstFromPreorder(vector<int> &preorder)
        {
            int min = INT_MIN, max = INT_MAX;
            int i = 0;
            return build(i, min, max, preorder);
        }
};

// Helper function to print the tree using level-order traversal
void levelOrder(TreeNode* root)
{
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    vector<string> result;

    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();

        if (curr)
        {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        }
        else
        {
            result.push_back("null");
        }
    }

    // Remove trailing "null" values from result
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    // Print final output
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
}

int main()
{
    // Input: preorder = [8, 5, 1, 7, 10, 12]
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Create Solution object
    Solution sol;
    
    // Build BST from preorder
    TreeNode* root = sol.bstFromPreorder(preorder);

    // Output BST using level-order traversal
    cout << "Output: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
