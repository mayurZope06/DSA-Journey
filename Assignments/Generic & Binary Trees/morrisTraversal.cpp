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
        vector<int> inorderTraversal(TreeNode* root)
        {
            vector<int> ans;
            TreeNode* curr = root;

            while(curr)
            {
                // left node is Null, then visit it and go right
                if(curr -> left == nullptr)
                {
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }

                //left node is not Null
                else
                {
                    //find inorder predecessor
                    TreeNode* pred = curr -> left;
                    while(pred -> right != curr && pred -> right)
                    {
                        pred = pred -> right;
                    }

                    //if pred, right node is Null, then go to left after establishing link form pred to curr
                    if(pred -> right == nullptr)
                    {
                        pred -> right = curr;
                        curr = curr -> left;
                    }
                    else
                    {
                        //left is already visited, go right
                        //after visiting curr node while removing the link
                        pred -> right = nullptr;
                        ans.push_back(curr -> val);
                        curr = curr -> right;
                    }
                }
            }
            return ans;
        }
};

// Utility function to create a new TreeNode
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// Function to create the tree from the given example
TreeNode* createTree() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->left->right->left = createNode(6);
    root->left->right->right = createNode(7);
    root->right->right->left = createNode(9);
    
    return root;
}

int main()
{
    // Create the example tree
    TreeNode* root = createTree();

    // Create an object of Solution class
    Solution sol;

    // Perform inorder traversal using Morris Traversal
    vector<int> result = sol.inorderTraversal(root);

    // Print the result
    cout << "Inorder Traversal: ";
    for(int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}