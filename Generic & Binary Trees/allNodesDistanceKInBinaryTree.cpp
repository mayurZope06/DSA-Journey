#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    int val;
};

class Solution 
{
    public:
        // step 1: I have to create child to parent mapping
        void mapParent(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&parentMap)
        {
            if(!root) return;
    
            if(root->left)
            {
                parentMap[root->left] = root;
                mapParent(root->left, parentMap);
            }
            if(root->right)
            {
                parentMap[root->right] = root;
                mapParent(root->right, parentMap);
            }
        }
    
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
        {
            unordered_map<TreeNode*, TreeNode*>parentMap;
            parentMap[root] = nullptr;
            mapParent(root, parentMap);
    
            unordered_map<TreeNode*, bool>visited;
            queue<TreeNode*>q;
            q.push(target);
            visited[target] = true;
    
            int currentLevel = 0;
            while(!q.empty())
            {
                int size = q.size(); // nodes in current level.
                if(currentLevel == k) break; // now my answer nodes should be present in queue itself
    
                currentLevel++;
                // Traverse over all nodes at the current level
                for(int i=0;i<size;i++)
                {
                    auto front = q.front(); q.pop();
    
                    if(front->left && visited.find(front->left) == visited.end())
                    {
                        // front has its left child, and it is not yet visited.
                        q.push(front->left);
                        visited[front->left] = true;  
                    }
                    if(front->right && visited.find(front->right) == visited.end())
                    {
                        // front has its right child, and it is not yet visited.
                        q.push(front->right);
                        visited[front->right] = true;  
                    }
    
                    // new thing here, have to process parent too.
                    auto parentNodeOfFront = parentMap[front];
                    if(parentNodeOfFront && visited.find(parentNodeOfFront) == visited.end())
                    {
                        // front has its parent node, and it is not yet visited.
                        q.push(parentNodeOfFront);
                        visited[parentNodeOfFront] = true;  
                    }
                }
            }
    
            vector<int>ans;
            while(!q.empty())
            {
                auto front = q.front(); q.pop();
                ans.push_back(front->val);
            }
            return ans;
        }
};

int main()
{
    /*
    Tree structure:
                3
              /   \
             5     1
            / \   / \
           6   2 0   8
              / \
             7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // Target node with value 5
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);
    
    cout << "Nodes at distance " << k << " from target " << target->val << ": ";
    for(int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}