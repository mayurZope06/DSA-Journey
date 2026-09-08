#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            
            if(root == NULL) {
                return NULL;
            }
            //case A: 
            //p and q are both on left side 
            //right -> neglect and left -> select
            if(p->val < root-> val && q->val < root-> val) {
                TreeNode* leftAns = lowestCommonAncestor(root->left, p , q);
                if(leftAns != NULL) {
                    return leftAns;
                }
            }
            //case B:
            //p and q are both on right side 
            if(p->val > root->val && q->val > root->val) {
                TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
                if(rightAns != NULL) {
                    return rightAns;
                }
            }
            //case C:
            //p in left subtree and q in right subtree
            //case D:
            // q in left subtree and p in right subtree
            return root;
        }
    };

// Function to manually create the BST [6,2,8,0,4,7,9,null,null,3,5]
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    
    TreeNode* p = root->left;   // Node with value 2
    TreeNode* q = root->right;  // Node with value 8

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}