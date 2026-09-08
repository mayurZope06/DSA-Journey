#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            queue<pair<TreeNode*, pair<int, int>>> q; // Node, {row, col}
            q.push({root, {0, 0}});
            map<int, map<int, multiset<int>>> mp; // col -> {row: [x, y, z....]}
            
            while(!q.empty()) {
                auto front = q.front(); q.pop();
                TreeNode* node = front.first;
                auto& coordinate = front.second;
                int row = coordinate.first;
                int col = coordinate.second;
                
                mp[col][row].insert(node->val);
                
                if(node->left)
                    q.push({node->left, {row + 1, col - 1}});
                
                if(node->right)
                    q.push({node->right, {row + 1, col + 1}});
            }
            
            // Store final vertical order into ans vector
            for(auto it : mp) {
                auto& colMap = it.second;
                vector<int> vLine;
                for(auto colMapIt : colMap) {
                    auto& mset = colMapIt.second;
                    vLine.insert(vLine.end(), mset.begin(), mset.end());
                }
                ans.push_back(vLine);
            }
            
            return ans;
        }
        
};

void printVerticalOrder(vector<vector<int>> result) {
    for(auto vLine : result) {
        for(int val : vLine) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Creating the tree:
    //         3
    //        / \
    //       9  20
    //          / \
    //         15  7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Print the vertical order
    cout << "Vertical order traversal:" << endl;
    printVerticalOrder(result);

    return 0;
}