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

void solve(Node* root, int level, vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    if(level == ans.size())
    {
        ans.push_back(root -> data);
    }
    solve(root -> left, level + 1, ans);
    solve(root -> right, level + 1, ans);
}
vector<int> leftView(Node* root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}

int main()
{
    //root[] = [1, 2, 3, 4, 5, NULL, NULL]
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = leftView(root);

    cout << "Left View of the Binary Tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}