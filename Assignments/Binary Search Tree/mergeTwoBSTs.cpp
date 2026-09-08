#include <iostream>
#include <vector>
#include <stack>
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

class Solution {
    public:
        //Function to return a list of integers denoting the node 
        //values of both the BST in a sorted order.
        vector<int> merge(Node *root1, Node *root2)
        {
            vector<int>ans; // stores sorted elements of both the trees;
            stack<Node*>sa, sb;
            Node* a = root1, *b = root2;
            while(a || b || !sa.empty() || !sb.empty()){
                while(a){
                    sa.push(a);
                    a = a->left;
                }
                while(b){
                    sb.push(b);
                    b = b->left;
                }
                
                if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
                    auto atop = sa.top();
                    ans.push_back(atop->data);
                    sa.pop();
                    a = atop->right;
                }
                else{
                    auto btop = sb.top();
                    sb.pop();
                    ans.push_back(btop->data);
                    b = btop->right;
                }
            }
            return ans;
        }
    };

// Helper function to create a new node
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Helper function to create BST from vector elements
Node* createBST(vector<int> vals) {
    Node* root = NULL;
    for (int val : vals) {
        root = insert(root, val);
    }
    return root;
}

// Inorder traversal to verify BST structure
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Creating first BST: [5, 3, 6, 2, 4]
    vector<int> vals1 = {5, 3, 6, 2, 4};
    Node* root1 = createBST(vals1);

    // Creating second BST: [2, 1, 3, N, N, N, 7, 6, N]
    Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->right->right = new Node(7);
    root2->right->right->left = new Node(6);

    Solution sol;
    vector<int> result = sol.merge(root1, root2);

    cout << "Merged BST in sorted order: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}