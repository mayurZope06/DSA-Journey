#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val) {
        this -> data = val;
        left = NULL;
        right = NULL;
    }
};

Node* createTree() {
    cout << "Enter the value for Node: " << endl;
    int value;
    cin >> value;

    if(value == -1) {
        return NULL;
    }

    else {
        Node* root = new Node(value);
        cout << "Adding leftchid for " << value << endl;
        root -> left = createTree();
        cout << "Adding rightchild for " << value << endl;
        root -> right = createTree();
        return root;
    }
}

int main()
{
    Node* root;
    root = createTree();
    cout << "Printing root " << root -> data << endl;
    return 0;
}