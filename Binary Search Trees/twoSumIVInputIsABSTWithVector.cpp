#include <iostream>
#include <vector>
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
        void storeInorder(TreeNode* root, vector<int> &inorder)
        {
            if(root == NULL)
            {
                return;
            }
            //LNR
            storeInorder(root -> left, inorder);
            inorder.push_back(root -> val);
            storeInorder(root -> right, inorder);
        }

        bool checkTwoSum(vector<int> arr, int target)
        {
            int n = arr.size();
            int s = 0;
            int e = n - 1;

            while(s < e)
            {
                int sum = arr[s] + arr[e];
                if(sum == target)
                {
                    return true;
                }
                if(sum > target)
                {
                    e--;
                }
                if(sum < target)
                {
                    s++;
                }
            }
            return false;
        }

        bool findTarget(TreeNode* root, int target)
        {
            vector<int> inorder;
            storeInorder(root, inorder);
            bool ans = checkTwoSum(inorder, target);
            return ans;
        }

};

// Helper function to insert a node in BST
TreeNode* insert(TreeNode* root, int val)
{
    if(!root)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Helper function to create BST from input array
TreeNode* createBST()
{
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    return root;
}

int main()
{
    // Create BST from input: [5, 3, 6, 2, 4, null, 7]
    TreeNode* root = createBST();
    
    // Target value
    int k = 9;

    // Create solution object
    Solution sol;
    bool result = sol.findTarget(root, k);

    // Print the result
    if(result)
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}
