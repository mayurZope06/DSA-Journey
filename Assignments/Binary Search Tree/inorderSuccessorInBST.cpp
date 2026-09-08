#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
        Node* inorderSuccessor(Node* root, Node* x)
        {
            Node* succ = 0;
            Node* curr = root;

            while(curr)
            {
                if(curr -> data > x -> data)
                {
                    succ = curr;
                    curr = curr -> left;
                }
                else
                {
                    curr = curr -> right;
                }
            }
            return succ;
        }
};

// Helper function to insert a node in BST
Node* insert(Node* root, int val)
{
    if(!root)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Helper function to search a node in BST
Node* search(Node* root, int key)
{
    if(root == nullptr || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    // Create BST with nodes [2, 1, 3]
    Node* root = nullptr;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    // Find the node with value 2
    Node* x = search(root, 2);

    // Create solution object and find the inorder successor
    Solution sol;
    Node* result = sol.inorderSuccessor(root, x);

    // Print the result
    if(result)
        cout << "Output: " << result->data << endl; // Should output 3
    else
        cout << "Output: null" << endl;

    return 0;
}