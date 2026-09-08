#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
        int countPairs(Node* root1, Node* root2, int x)
        {
            int ans = 0;
            stack<Node*> s1, s2;
            Node* a = root1;
            Node* b = root2;

            while(1)
            {
                while(a)
                {
                    // inorder
                    s1.push(a);
                    a = a -> left;
                }
                while(b)
                {
                    // reverse inorder
                    s2.push(b);
                    b = b -> right;
                }

                if(s1.empty() || s2.empty())
                {
                    break;
                }

                auto atop = s1.top();
                auto btop = s2.top();

                int sum = atop -> data + btop -> data;

                if(sum == x)
                {
                    ++ans;
                    s1.pop();
                    s2.pop();
                    a = atop -> right;
                    b = btop -> left;
                }
                else if(sum < x)
                {
                    s1.pop();
                    a = atop -> right;
                }
                else
                {
                    s2.pop();
                    b = btop -> left;
                }
            }
            return ans;
        }
};

// Function to insert nodes in a BST
Node* insert(Node* root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

int main()
{
    // Create BST1
    Node* root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 3);
    root1 = insert(root1, 7);
    root1 = insert(root1, 2);
    root1 = insert(root1, 4);
    root1 = insert(root1, 6);
    root1 = insert(root1, 8);

    // Create BST2
    Node* root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 6);
    root2 = insert(root2, 15);
    root2 = insert(root2, 3);
    root2 = insert(root2, 8);
    root2 = insert(root2, 11);
    root2 = insert(root2, 18);

    int x = 16;
    
    Solution obj;
    cout << "Number of pairs with sum " << x << ": " << obj.countPairs(root1, root2, x) << endl;

    return 0;
}