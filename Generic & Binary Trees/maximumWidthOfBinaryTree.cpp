#include <iostream>
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
        int widthOfBinaryTree(TreeNode* root)
        {
            unsigned long long maxWidth = 0;
            if(!root)
            {
                return maxWidth;
            }
            
            queue<pair<TreeNode*, unsigned long long>> q;
            q.push({root, 1});

            while(!q.empty())
            {
                unsigned long long size = q.size(); // this is my current level's number of nodes.
                unsigned long long leftMostNodeIndex = q.front().second;
                unsigned long long rightmostNodeIndex = q.back().second;
                unsigned long long currentLevelWidth = rightmostNodeIndex - leftMostNodeIndex + 1;
                maxWidth = max(maxWidth, currentLevelWidth);
                
                //Treaverse over all nodes at the current level
                for(unsigned long long i = 0; i < size; i++)
                {
                    auto front = q.front();
                    q.pop();
                    auto node = front.first;
                    auto index = front.second;

                    //process its child and assign them the index
                    if(node -> left)
                        q.push({node -> left, 2 * index});
                    if(node -> right)
                        q.push({node -> right, 2 * index + 1});
                }
            }
            return maxWidth;
        }

};

int main()
{
    /*
    Tree structure:
                1
              /   \
             3     2
            /       \
           5         9
          /           \
         6             7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << result << endl;

    return 0;
}