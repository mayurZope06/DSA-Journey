#include <iostream>
#include <unordered_map>
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

void fun(Node* root, unordered_map<int, bool> &visited, bool &ans)
{
    if(root == 0)
    {
        return;
    }

    //visit the node
    visited[root -> data] = 1;
    if(root -> left == 0 && root -> right == 0)
    {
        //leaf node
        int xpl = root -> data + 1;
        int xml = root -> data - 1 == 0 ? root -> data : root -> data - 1;

        if(visited.find(xpl) != visited.end() && visited.find(xml) != visited.end())
        {
            ans = true;
            return;
        }
    }
    fun(root -> left, visited, ans);
    fun(root -> right, visited, ans);
}

bool isDeadEnd(Node* root)
{
    bool ans = false; // tells if there was a Dead End
    unordered_map<int, bool> visited;
    fun(root, visited, ans);
    return ans;
}

// Helper function to insert a node in BST
Node* insert(Node* root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

int main()
{
    // Create the tree
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);

    if (isDeadEnd(root))
    {
        cout << "Yes, there is a dead end in the BST." << endl;
    }
    else
    {
        cout << "No, there is no dead end in the BST." << endl;
    }

    return 0;
}