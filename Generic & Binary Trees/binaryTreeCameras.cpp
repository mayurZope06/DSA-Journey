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
        // Solve function returns:
        // 0 - Node is not covered
        // 1 - Node is covered by a camera
        // 2 - Node has a camera installed
        int solve(TreeNode*root, int&cameras)
        {
            if(!root) return 1; // null nodes are assumed to be covered.
    
            int left = solve(root->left, cameras);
            int right = solve(root->right, cameras);
    
            if(left == 0 || right == 0) // either nodes are not covered
            {
                cameras++;
                return 2; // my cam is installed
            }
    
            if(left == 2 || right == 2)
                return 1; // yeah, i am already covered by my child.
    
            return 0; // I'm not covered.
        }
    
        int minCameraCover(TreeNode* root) 
        {
            int cameras = 0;
            int rootState = solve(root, cameras);
            if(rootState == 0) // not covered
                cameras++;
            return cameras;
        }
};

int main()
{
    /*
    Tree structure:
                0
               /
              0
               \
                0
                 \
                  0
                 /
                0
    */
    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->left->right->right = new TreeNode(0);
    root->left->right->right->left = new TreeNode(0);

    Solution sol;
    int result = sol.minCameraCover(root);
    cout << "Minimum number of cameras needed: " << result << endl;

    return 0;
}