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

class Solution {
    public:
        void solve(TreeNode* root, int k, int &count, TreeNode *&ans) {
            if(root == NULL) {
                return ;
            }
            //LNR
            //L
            solve(root->left, k, count, ans);
            //N
            count++;
            if(count == k) {
                ans = root;
                return;
            }
            //R
            solve(root->right,k,count, ans);   
        }
        int kthSmallest(TreeNode* root, int k) {
            int count = 0;
            TreeNode* ans = NULL;
            solve(root,k,count,ans);
            return ans->val;
        }
    };

// Function to manually create the BST [3,1,4,null,2]
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    int k = 1;  // Find the 1st smallest element

    Solution sol;
    cout << "The " << k << "th smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}