#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left,* right;
    Node(int d){
    	data=d;
    	left=NULL;
    	right=NULL;
    }
};

class Solution
{
    public:
        int sum (Node* root)
        {
            if(!root)
            {
                return 0;
            }
            if(!root -> left && !root -> right)
            {
                // leaf node
                int temp = root -> data;
                root -> data = 0;
                return temp;
            }
            int lsum = sum(root -> left);
            int rsum = sum(root -> right);
            int temp = root -> data;
            root -> data = lsum + rsum;
            return root -> data + temp;
        }
        void toSumTree(Node* node)
        {
            sum(node);
        }

        void levelOrder(Node* root)
        {
            if(!root)
                return;

            queue<Node*> q;
            q.push(root);

            while(!q.empty())
            {
                Node* front = q.front();
                q.pop();
                
                cout << front->data << " ";

                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
        }
};

int main()
{
    // Creating the tree:
    //          10
    //       /      \
    //     -2        6
    //    /   \     /  \
    //  8     -4   7    5
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution sol;
    cout << "Level order before conversion: ";
    sol.levelOrder(root);
    cout << endl;

    // Convert to sum tree
    sol.toSumTree(root);

    cout << "Level order after conversion: ";
    sol.levelOrder(root);
    cout << endl;

    return 0;
}