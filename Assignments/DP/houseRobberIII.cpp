#include <iostream>
#include <vector>
#include <unordered_map>
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
        int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp){
            if(!root) return 0;
    
            if(dp.find(root) != dp.end()) return dp[root];
    
            int robThisHouse = 0, dontRobThisHouse = 0;
    
            // rob current house
            robThisHouse += root->val;
            if(root->left)
                robThisHouse += solve(root->left->left, dp) + solve(root->left->right, dp);
            if(root->right)
                robThisHouse += solve(root->right->left, dp) + solve(root->right->right, dp);
    
            // dont rob current house
            dontRobThisHouse = solve(root->left, dp) + solve(root->right, dp);
    
            dp[root] = max(robThisHouse, dontRobThisHouse);
            return dp[root];
        }
    
        int rob(TreeNode* root) {
            unordered_map<TreeNode*, int> dp;
            return solve(root, dp);
        }
    };

//     3
//     / \
//    2   3
//     \    \
//      3    1


int main() {
    // Building the tree: [3,2,3,null,3,null,1]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution sol;
    int result = sol.rob(root);
    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}