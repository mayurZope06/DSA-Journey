#include <iostream>
#include <queue>
#include <unordered_map>
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
        Node* makeNodetoParentMappingAndFindTargetNode(Node* root, unordered_map<Node*, Node*>& parentMap, int target) 
        {
            queue<Node*> q;
            Node* targetNode = 0;
            q.push(root);
            parentMap[root] = 0;
            while (!q.empty()) {
                Node* front = q.front();
                q.pop();
                if (front->data == target) 
                {
                    targetNode = front;
                }
                if (front->left) 
                {
                    q.push(front->left);
                    parentMap[front->left] = front;
                }
                if (front->right) 
                {
                    q.push(front->right);
                    parentMap[front->right] = front;
                }
            }
            return targetNode;
        }

        int burnTheTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) 
        {
            unordered_map<Node*, bool> isBurnt;
            queue<Node*> q; // currently set on fire nodes.
            int T = 0;
            q.push(targetNode);
            isBurnt[targetNode] = 1;
            while (!q.empty()) {
                int size = q.size();
                bool isFireSpreaded = 0;
                for (int i = 0; i < size; ++i) 
                {
                    Node* front = q.front();
                    q.pop();
                    if (front->left && !isBurnt[front->left]) 
                    {
                        q.push(front->left);
                        isBurnt[front->left] = 1;
                        isFireSpreaded = 1;
                    }
                    if (front->right && !isBurnt[front->right]) 
                    {
                        q.push(front->right);
                        isBurnt[front->right] = 1;
                        isFireSpreaded = 1;
                    }
                    if (parentMap[front] && !isBurnt[parentMap[front]]) 
                    {
                        q.push(parentMap[front]);
                        isBurnt[parentMap[front]] = 1;
                        isFireSpreaded = 1;
                    }
                }
                if (isFireSpreaded) ++T;
            }
            return T;
        }

        int minTime(Node* root, int target)
        {
            unordered_map<Node*, Node*> parentMap; // Node -> its parent pointers.
            Node* targetNode = makeNodetoParentMappingAndFindTargetNode(root, parentMap, target);
            return burnTheTree(targetNode, parentMap);
        }
};

int main()
{
    /*
    Tree structure:
                1
              /   \
             2     3
            / \      \
           4   5      6
          / \          \
         7   8          9
                          \
                          10
    Target Node = 8
    Expected Output: 7 (time to burn the tree completely)
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);

    Solution sol;
    int target = 8;
    int result = sol.minTime(root, target);
    cout << "Minimum time to burn the tree: " << result << endl;

    return 0;
}