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
        void solve(TreeNode* root, int target, int sum, vector<int> &path, vector<vector<int>> &ans)
        {
            if(root == NULL)
            {
                return;
            }

            //root palla not null h
            sum = sum + root -> val;
            path.push_back(root -> val);
            
            //check for leaf node
            if(root -> left == NULL && root -> right == NULL)
            {
                //root is a leaf node
                if(sum == target)
                {
                    ans.push_back(path);
                }
              
                //backtrack
                path.pop_back();
                return;
                
                // or
                // if(sum == target) {
                //     ans.push_back(path);
                //     path.pop_back();
                //     return;
                // }
                // else {
                //     path.pop_back();
                //     return;
                // }
            }
            
            solve(root -> left, target, sum, path, ans);
            solve(root -> right, target, sum, path, ans);
            
            //backtrack
            path.pop_back();
        }
        vector<vector<int>> pathSum(TreeNode* root, int targetSum)
        {
            int sum = 0;
            vector<int> path;
            vector<vector<int>> ans;
            solve(root, targetSum, sum, path, ans);
            return ans;
        }
};

int main() {
    // Creating the tree: root = [5,4,8,11,null,13,4,7,2,null,null,5,1]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    Solution sol;
    
    vector<vector<int>> res = sol.pathSum(root, targetSum);
    for(auto i: res)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
