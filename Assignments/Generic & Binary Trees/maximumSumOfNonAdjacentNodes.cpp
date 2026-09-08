#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution 
{
    public:
        // Function to return the maximum sum of non-adjacent nodes.
        pair<int, int> getMaxSum_helper(Node* root) 
        {
            if (!root) return {0, 0};
    
            auto left = getMaxSum_helper(root->left);
            auto right = getMaxSum_helper(root->right);
    
            // sum including the node;
            int a = root->data + left.second + right.second;
    
            // sum excluding the node;
            int b = max(left.first, left.second) + max(right.first, right.second);
            return {a, b};
        }
    
        int getMaxSum(Node* root) 
        {
            auto ans = getMaxSum_helper(root);
            return max(ans.first, ans.second);

        }
};

int main()
{
        /*
        Tree structure:
                    1
                   / \
                  2   3
                 / \   \
                4   5   6
        Maximum sum: 1 + 4 + 5 + 6 = 16
        */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    Solution sol;
    int result = sol.getMaxSum(root);
    cout << "Maximum sum of non-adjacent nodes: " << result << endl;
    
    return 0;
}