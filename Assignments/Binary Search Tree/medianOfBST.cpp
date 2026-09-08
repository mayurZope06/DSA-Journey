#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int findNodeCount(Node* root) {
    int count = 0;
    Node* curr = root;

    while (curr) {
        // left node is NULL, then visit it and go right;
        if (curr->left == nullptr) {
            count++;
            curr = curr->right;
        } 
        // left node is NOT NULL
        else {
            // find inorder predecessor
            Node* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // if pred right node is NULL, then go left after establishing link from pred to curr;
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            } 
            // left is already visited, Go right after visiting curr node, while removing the link.
            else {
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }

    return count;
}

float findActualMedian(Node* root, int n) {
    int i = 0;
    int odd1 = (n + 1) / 2, odd1Val = -1;
    int even1 = n / 2, even1Val = -1;
    int even2 = (n / 2) + 1, even2Val = -1;
    Node* curr = root;

    while (curr) {
        // left node is NULL, then visit it and go right;
        if (curr->left == nullptr) {
            i++;
            if (i == odd1) odd1Val = curr->data;
            if (i == even1) even1Val = curr->data;
            if (i == even2) even2Val = curr->data;
            curr = curr->right;
        } 
        // left node is NOT NULL
        else {
            // find inorder predecessor
            Node* pred = curr->left;
            while (pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // if pred right node is NULL, then go left after establishing link from pred to curr;
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            } 
            else {
                // left is already visited, Go right after visiting curr node, while removing the link.
                pred->right = nullptr;
                i++;
                if (i == odd1) odd1Val = curr->data;
                if (i == even1) even1Val = curr->data;
                if (i == even2) even2Val = curr->data;
                curr = curr->right;
            }
        }
    }

    float median = 0.0;
    if ((n & 1) == 0) {
        // even
        median = (even1Val + even2Val) / 2.0;
    } else {
        // odd
        median = odd1Val;
    }
    return median;
}

float findMedian(struct Node *root) {
    int n = findNodeCount(root);
    return findActualMedian(root, n);
}

// Main function to create BST and call findMedian()
int main() {
    // Creating the given BST:
    //       6
    //     /   \
    //    3     8   
    //   / \   / \
    //  1   4 7   9
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // Find and print the median of BST
    float median = findMedian(root);
    cout << "Median of BST: " << median << endl;  // Output: 6

    return 0;
}
