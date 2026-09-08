#include <iostream>
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
        vector<vector<int>> zigZagLevelOrder(TreeNode* root)
        {
            vector<vector<int>> ans;
            if(!root)
            {
                return ans;
            }
            bool LtoRdir = true;
            queue<TreeNode* > q;
            q.push(root);

            while(!q.empty())
            {
                int width = q.size();
                vector<int> oneLevel(width);
                for(int i = 0; i < width; ++i)
                {
                    TreeNode* front = q.front();
                    q.pop();
                    int index = LtoRdir ? i : width - i - 1;
                    oneLevel[index] = front -> val;

                    if(front -> left)
                    {
                        q.push(front -> left);
                    }
                    if(front -> right)
                    {
                        q.push(front -> right);
                    }
                }
                //Toggle the direction
                LtoRdir = !LtoRdir;
                ans.push_back(oneLevel);
            }
            return ans;
        }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigZagLevelOrder(root);

    // Printing the result
    for(auto level : result)
    {
        for(int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}