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
        pair<int, int> height(Node* root)
        {
            if(!root)
            {
                return {0, 0};
            }
            auto lh = height(root -> left);
            auto rh = height(root -> right);

            int sum = root -> data;

            if(lh.first == rh.first)
            {
                sum += lh.second > rh.second ? lh.second : rh.second;
            }
            else if(lh.first > rh.first)
            {
                sum += lh.second;
            }
            else
            {
                sum += rh.second;
            }
            return {max(lh.first, rh.first) + 1, sum};
        }
        int sumOfLongRootToLeafPath(Node* root)
        {
            auto h = height(root);

            return h.second;
        }
};

int main()
{
    /*
    Tree structure:
                4
              /   \
             2     5
            / \   / \
           7   1 1   2
          /
         3
        /
       6
    Longest path: 4 -> 2 -> 7 -> 3 -> 6
    Sum of the longest path: 4 + 2 + 7 + 3 + 6 = 22
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(1);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->left->left = new Node(6);

    Solution sol;
    int result = sol.sumOfLongRootToLeafPath(root);
    cout << "Sum of the longest root-to-leaf path: " << result << endl;

    return 0;
}