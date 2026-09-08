#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;

    Node(int val)
    {
        data = val;
        left=right= NULL;
    }
};

class Solution
{
    public:
        void LeftBoundary(Node* root, vector<int> &ans)
        {
            if(root == NULL)
            {
                return;
            }
            if(root -> left == NULL && root -> right == NULL)
            {
                //leaf node
                return;
            }

            ans.push_back(root ->data);

            if(root -> left != NULL)
            {
                LeftBoundary(root -> left, ans);
            }
            else
            {
                LeftBoundary(root -> right, ans);
            }
        }

        void LeafBoundary(Node* root, vector<int> &ans)
        {
            if(root == NULL)
            {
                return;
            }
            if(root -> left == NULL && root -> right == NULL)
            {
                //leaf node
                ans.push_back(root ->data);
            }

            LeafBoundary(root -> left, ans);
            LeafBoundary(root -> right, ans);
        }

        void RightBoundary(Node* root, vector<int> &ans)
        {
            if(root == NULL)
            {
                return;
            }
            if(root -> left == NULL && root -> right == NULL)
            {
                //leaf node
                return;
            }

            if(root -> right != NULL)
            {
                RightBoundary(root -> right, ans);
            }
            else
            {
                RightBoundary(root -> left, ans);
            }

            //kyokki mujhe reverse order store krna h 
            ans.push_back(root ->data);
        }
        vector<int> boundary(Node* root)
        {
            vector<int> ans;

            if(root == NULL)
            {
                return ans;
            }

            //A -> root node
            ans.push_back(root -> data);
            //B -> Left subtree -> left boundary
            LeftBoundary(root -> left, ans);
            //C -> left subtree -> leaf boundary
            LeafBoundary(root -> left, ans);
            //D -> right subtree -> leaf boundary
            LeafBoundary(root -> right, ans);
            //E -> right subtree -> right boundary
            RightBoundary(root -> right, ans);

            return ans;
        }
};

int main()
{
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    
    Solution sol;
    vector<int> boundaryNodes = sol.boundary(root);
    
    // Printing boundary traversal
    cout << "Boundary traversal: ";
    for (int node : boundaryNodes)
    {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
