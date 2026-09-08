#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
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
        vector<int> bottomView(Node* root)
        {
            queue<pair<Node*, int>> q;
            //to maintain initial state 
            q.push(make_pair(root,0));
            unordered_map<int, Node*> distMap;
            int minDist = INT_MAX;
            int maxDist = INT_MIN;

            //rule-> left(-1), right(+1) in distance

            while(!q.empty())
            {
                pair<Node*, int> frontPair = q.front();
                q.pop();

                Node* frontNode = frontPair.first;
                int hd = frontPair.second;
                minDist = min(minDist, hd);
                maxDist = max(maxDist, hd);

                distMap[hd] = frontNode;

                //left child
                if(frontNode -> left != NULL)
                {
                    q.push(make_pair(frontNode -> left, hd - 1));
                }
                //right child
                if(frontNode -> right != NULL)
                {
                    q.push(make_pair(frontNode -> right, hd + 1));
                }
            }
            vector<int> ans;
            for(int i = minDist; i <= maxDist; i++) 
            {
                Node* temp = distMap[i];
                ans.push_back(temp->data);
            }
            return ans;

        }
};

int main()
{
    //root[] = [1, 2, 3, 4, 5, NULL, NULL]
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution s1;
    vector<int> result = s1.bottomView(root);

    cout << "Bottom View of the Binary Tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}