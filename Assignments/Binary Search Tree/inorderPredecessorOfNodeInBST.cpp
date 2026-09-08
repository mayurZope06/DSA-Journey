#include <iostream>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;
    
        Node(int data) {
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
    };

Node* findPredecessor (Node* root, Node *p)
{
    Node* pred = 0;
    Node* curr = root;

    while(curr)
    {
        if(curr -> data < p -> data)
        {
            pred = curr;
            curr = curr -> right;
        }
        else
        {
            curr = curr -> left;
        }
    }
    return pred;
}


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

// Helper function to search for a node in BST
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
    // Create BST with nodes [5, 3, 7, 2, 4, 6, 8]
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Find the node with value 6
    Node* p = search(root, 6);

    // Find the inorder predecessor
    Node* pred = findPredecessor(root, p);

    // Print the result
    if(pred)
        cout << "Inorder predecessor of " << p->data << " is: " << pred->data << endl;
    else
        cout << "No inorder predecessor found for " << p->data << endl;

    return 0;
}