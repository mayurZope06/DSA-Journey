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
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            if(!p && !q)
            {
                return true;
            }
            if(p && q)
            {
                return (p -> val == q -> val) && isSameTree(p -> left, q-> left) && isSameTree(p -> right, q -> right);
            }
            return false;
        }
};

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Creating tree 2: q = [1,2,3]
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    if(sol.isSameTree(p, q))
    {
        cout << "The trees are the same." << endl;
    }
    else
    {
        cout << "The trees are not the same." << endl;
    }
    
    return 0;
}