#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

vector<int> diagonal (Node* root)
{
    vector<int> ans;
    if(!root)
    {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        while(temp) // temp != NULL
        {
            ans.push_back(temp -> data);
            if(temp -> left)
            {
                //baad me dekhna hai
                q.push(temp -> left);
            }
            temp = temp -> right;
        }
    }
    return ans;
}


// Function to build the tree manually as per given input
Node* buildTree() {
    /*
       Tree structure:
             8
            / \
           3   10
          / \    \
         1   6    14
            / \   /
           4   7 13
    */
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    return root;
}

int main() {
    Node* root = buildTree();

    // Get the diagonal traversal
    vector<int> result = diagonal(root);

    // Print the diagonal elements
    cout << "Diagonal Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}