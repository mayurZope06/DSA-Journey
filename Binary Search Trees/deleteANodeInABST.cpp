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
        int getMax(TreeNode* root)
        {
            if(root == NULL)
            {
                return -1;
            }
            while(root -> right != NULL)
            {
                root = root -> right;
            }
            return root -> val;
        }
        int getMin(TreeNode* root)
        {
            if(root == NULL)
            {
                return -1;
            }
            while(root -> left != NULL)
            {
                root = root -> left;
            }
            return root -> val;
        }
        TreeNode* deleteNode (TreeNode* root, int key)
        {
            if(root == NULL)
            {
                return NULL;
            }
            if(root -> val == key)
            {
                //match
                //ab mujhe node delete krni h

                //cases:
                //with 0 child
                if(root -> left == NULL && root -> right == NULL)
                {
                    delete root;
                    return NULL;
                }

                //with left child only
                if(root -> left != NULL && root -> right == NULL)
                {
                    TreeNode* leftChild = root -> left;
                    root -> left = NULL;
                    delete root;
                    return leftChild;
                }

                //with right child only
                if(root -> left == NULL && root -> right != NULL)
                {
                    TreeNode* rightChild = root -> right;
                    root -> right = NULL;
                    delete root;
                    return rightChild;
                }

                //with both left and right child 
                if(root -> left != NULL && root -> right != NULL)
                {
                    // By inorder predecessor
                    // to find just chotta element
                    int maxVal = getMax(root -> left);
                    //replace root node's value with maxVal

                    root -> val = maxVal;
                    //delete actual node of maxVal;
                    root -> left = deleteNode(root -> left, maxVal);
                    return root;

                    // // using inorder successor
                    // int minVal = getMin(root -> right);
                    // root -> val = minVal;
                    // root -> right = deleteNode(root -> right, minVal);
                    // return root;
                }
            }
            else
            {
                //not match
                //left ya right jao
                if(key < root -> val)
                {
                    //left jao
                    root -> left = deleteNode(root -> left, key);
                }
                else
                {
                    //right jao
                    root -> right = deleteNode(root -> right, key);
                }
            }
            return root;
        }
};

void levelOrder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        
        cout << temp -> val << " ";

        if (temp -> left != NULL)
        {
            q.push(temp -> left);
        }
        if (temp -> right != NULL)
        {
            q.push(temp -> right);
        }
    }
    cout << endl;
}

int main()
{
    // Creating the tree [5,3,6,2,4,null,7]
    TreeNode* root = new TreeNode(5);
    root -> left = new TreeNode(3);
    root -> right = new TreeNode(6);
    root -> left -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(4);
    root -> right -> right = new TreeNode(7);

    cout << "Level order before deletion: ";
    levelOrder(root);

    Solution sol;
    int key = 3;
    root = sol.deleteNode(root, key);

    cout << "Level order after deleting " << key << ": ";
    levelOrder(root);

    return 0;
}