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

class Solution {
    public:
        void storeInorder(TreeNode* root, vector<int>& inorder) {
            if(root == NULL) {
                return;
            }
            //LNR
            storeInorder(root->left, inorder);
            inorder.push_back(root->val);
            storeInorder(root->right, inorder);
        } 
        void updateTree(TreeNode* root, vector<int> inorder, int &index) {
            if(root == NULL) {
                return;
            }
            //LNR
            updateTree(root->left, inorder, index);
            root->val = inorder[index];
            index++;
            updateTree(root->right, inorder, index);
        }
        TreeNode* bstToGst(TreeNode* root) {
            if(root == NULL) {
                return NULL;
            }
            if(root->left == NULL && root->right == NULL) {
                return root;
            }
            //step1: store inorder
            vector<int> inorder;
            storeInorder(root, inorder);
            //step2: update inorder as per question rules
            int n = inorder.size();
            for(int i=n-1; i>=0; i--) {
                int currVal = inorder[i];
                int nextVal = 0;
                if(i+1 < n) {
                    nextVal = inorder[i+1];
                }
                int sum = currVal + nextVal;
                //replace krre h 
                inorder[i] = sum;
            }
            //step3: update tree using inorder
            int index= 0;
            updateTree(root, inorder,index);
            return root;
    
        }
    };

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper function to manually create the BST
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = createTestTree();

    Solution sol;
    root = sol.bstToGst(root);

    cout << "Inorder Traversal of the Greater Sum Tree:\n";
    printInorder(root);
    cout << endl;

    return 0;
}