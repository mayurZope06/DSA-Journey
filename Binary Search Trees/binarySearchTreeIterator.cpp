#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator 
{
    stack<TreeNode*>st; // using this stack, I'm doing LNR, inorder traversal.
    void pushLeftNodes(TreeNode*root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
    public:
        BSTIterator(TreeNode* root) 
        {
            pushLeftNodes(root);
        }
        
        int next() 
        {
            auto top = st.top();
            st.pop();

            if(top->right)
                pushLeftNodes(top->right);

            return top->val;
        }
        
        bool hasNext() 
        {
            return !st.empty();
        }
};


// Helper function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) 
{
    if(!root)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Helper function to create BST from input array
TreeNode* createBST()
{
    TreeNode* root = nullptr;
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 9);
    root = insert(root, 20);
    return root;
}

int main()
{
    // Create BST from input: [7, 3, 15, null, null, 9, 20]
    TreeNode* root = createBST();

    // Initialize BSTIterator
    BSTIterator it(root);

    // Simulate the operations
    cout << "Output:" << endl;
    cout << "[null, ";
    cout << it.next() << ", ";  // 3
    cout << it.next() << ", ";  // 7
    cout << (it.hasNext() ? "true" : "false") << ", ";  // true
    cout << it.next() << ", ";  // 9
    cout << (it.hasNext() ? "true" : "false") << ", ";  // true
    cout << it.next() << ", ";  // 15
    cout << (it.hasNext() ? "true" : "false") << ", ";  // true
    cout << it.next() << ", ";  // 20
    cout << (it.hasNext() ? "true" : "false") << "]" << endl;  // false

    return 0;
}