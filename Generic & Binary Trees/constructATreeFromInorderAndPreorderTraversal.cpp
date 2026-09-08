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

    int getIndexInorder(vector<int> inorder, int target)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructTree(unordered_map<int,int> &valMap, vector<int> &preorder, vector<int> &inorder, int &preOrderIndex, int inorderStart, int inorderEnd, int size)
    {
        //base case
        if(preOrderIndex >= size)
        {
            return NULL;
        }
        if(inorderStart > inorderEnd)
        {
            return NULL;
        }

        //process the first element of the preorder as root
        //step1: get element from preorder and create root node for it 

        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);

        //step2: find this element inside inorder and call for left and rigth 
        int elementIndexInsideInorder = valMap[element];
        //inorder left part -> index inorderStart to elementIndexInsideInorder-1
        //inorder right part -> index elementIndexInsideInorder+1 to inorderEnd

        root -> left = constructTree(valMap, preorder, inorder, preOrderIndex, inorderStart, elementIndexInsideInorder - 1, size);
        root -> right = constructTree(valMap, preorder, inorder, preOrderIndex, elementIndexInsideInorder + 1, inorderEnd, size);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int preIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size() - 1;
        int size = inorder.size();

        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);
        TreeNode* root = constructTree(valMap, preorder, inorder, preIndex, inOrderStart, inOrderEnd, size);
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "Output: ";
    printLevelOrder(root);  // Expected Output: [3,9,20,null,null,15,7]

    return 0;
}