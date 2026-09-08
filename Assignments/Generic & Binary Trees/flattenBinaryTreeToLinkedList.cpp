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
        void flatten(TreeNode* root)
        {
            TreeNode* curr = root;

            while(curr)
            {
                if(curr -> left)
                {
                    TreeNode* pred = curr -> left;

                    while(pred -> right)
                    {
                        pred = pred -> right;
                    }
                    pred -> right = curr -> right;
                    curr -> right = curr -> left;
                    curr -> left = nullptr;
                }
                curr = curr -> right;
            }
        }
        void printFlattenedTree(TreeNode* root)
        {
            while(root)
            {
                cout << root->val << " ";
                root = root->right;
            }
            cout << endl;
        }
};

int main()
{
    /*
    Tree structure:
                1
              /   \
             2     5
            / \     \
           3   4     6
    Expected flattened list:
    1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    sol.printFlattenedTree(root);

    return 0;
}