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

class BSTIterator {
    stack<TreeNode*>st; // using this stack, I'm doing LNR, inorder traversal.
    stack<TreeNode*>revSt; // reverse inorder traversal
    void pushLeftNodes(TreeNode*root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    void pushRightNodes(TreeNode*root){
        while(root){
            revSt.push(root);
            root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
        pushRightNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();

        if(top->right)
            pushLeftNodes(top->right);

        return top->val;
    }

    int before() {
        auto top = revSt.top();
        revSt.pop();

        if(top->left)
            pushRightNodes(top->left);

        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    bool hasBefore() {
        return !revSt.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator it(root);

        int i = it.next(); // smalled, L -> R
        int j = it.before(); // largest, R -> L

        while(i < j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k)
                i = it.next(); // start++
            else
                j = it.before(); // end--
        }
        return false;
    }
};

// Helper function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) {
    if(!root)
        return new TreeNode(val);
    
    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int main()
{
    // Create the BST: [5, 3, 6, 2, 4, NULL, 7]
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    int k = 9;

    // Create a solution object and check if target exists
    Solution sol;
    bool result = sol.findTarget(root, k);

    // Print the result
    if(result)
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}