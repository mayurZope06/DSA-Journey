#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
    void createMapping (unordered_map<int, int> &valueToIndex, vector<int> inorder)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            int element = inorder[i];
            int index = i;
            valueToIndex[element] = index;
        }
    }

    TreeNode* constructTree(unordered_map<int,int> &valMap, vector<int> &postorder, vector<int>& inorder, int &postIndex, int inorderStart, int inorderEnd, int size)
    {
        //base case
        if(postIndex < 0)
        {
            return NULL;
        }
        if(inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = postorder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);
        int index = valMap[element];

        //right call
        root -> right = constructTree(valMap, postorder, inorder, postIndex, index + 1, inorderEnd, size);
        
        //left call
        root->left = constructTree(valMap, postorder, inorder, postIndex, inorderStart, index-1, size);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int postIndex = postorder.size() - 1;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = inorder.size();

        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);

        TreeNode* root = constructTree(valMap, postorder, inorder, postIndex, inorderStart, inorderEnd, size);
        return root;
    }
};

// Function to print tree in level-order format [3,9,20,null,null,15,7]
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    vector<string> result;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing "null" values from output
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    // Print output in required format
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> inorder = {9, 15, 7, 20, 3};
    vector<int> postorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(postorder, inorder);

    cout << "Output: ";
    printLevelOrder(root);  // Expected Output: [3,9,20,null,null,15,7]

    return 0;
}