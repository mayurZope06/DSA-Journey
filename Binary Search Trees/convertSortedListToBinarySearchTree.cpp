#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        int getLength(ListNode*& head) {
            ListNode* temp = head;
            int cnt = 0;
            while(temp != NULL) {
                cnt++;
                temp = temp ->next;
            }
            return cnt;
        }
        TreeNode* solve(ListNode*& head, int n) {
            if(head == NULL || n <= 0) {
               return NULL; 
            }
            //LNR
            //L
            TreeNode* leftSubTree = solve(head, n/2);
            //N
            //ab head mid node pr khada hoga
            TreeNode* root = new TreeNode(head->val);
            root->left = leftSubTree;
            //ab head mid pr khada tha, usko aage bhejo 
            head = head -> next;
            //ab head right part of LL k start node pr khada hoga 
            TreeNode* rightSubtree = solve(head, n-n/2-1);
            root->right  = rightSubtree;
            return root;
        }
        TreeNode* sortedListToBST(ListNode* head) {
            int n = getLength(head);
            TreeNode* root = solve(head, n);
            return root;
        }
    };

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    int arr[] = {-10, -3, 0, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, size);

    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}