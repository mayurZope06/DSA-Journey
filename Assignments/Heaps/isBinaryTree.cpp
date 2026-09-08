#include <iostream>
using namespace std;

struct Node
{
    public:
        int data;
        Node* right, *left;

        Node(int x)
        {
            data = x;
            right = left = NULL;
        }
};

int nodeCount(struct Node* root)
{
    if(!root)
        return 0;
    
        int l = nodeCount(root -> left);
        int r = nodeCount(root -> right);

        return 1 + l + r;
}

bool isCBT (struct Node* root, int i, int &n)
{
    if(!root)
        return true;

    if(i > n)
        return false;

    return isCBT(root -> left, 2 * i, n) && isCBT(root -> right, 2 * i + 1, n);
}

bool isMaxOrder(struct Node* root)
{
    if (!root)
    {
        return true;
    }
    int l = isMaxOrder(root -> left);
    int r = isMaxOrder(root -> right);
    int ans = false;

    if(!root -> left && !root -> right)
    {
        ans = true;
    }
    else if(root -> left && !root -> right)
    {
        ans = root -> data > root -> left -> data;
    }
    else
    {
        ans = root -> data > root -> left -> data && root -> data > root -> right -> data;
    }

    return ans && l && r;    
}
class Solution
{
    public:
        bool isHeap(struct Node* tree)
        {
            int n = nodeCount(tree);
            int i = 1;
            return isCBT(tree, i, n) && isMaxOrder(tree);
        }
};

int main()
{
    // Example: Creating a valid max heap
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    Solution sol;
    if (sol.isHeap(root))
    {
        cout << "The given tree is a Heap\n";
    }
    else
    {
        cout << "The given tree is NOT a Heap\n";
    }

    return 0;
}