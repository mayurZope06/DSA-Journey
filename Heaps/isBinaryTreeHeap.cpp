#include <iostream>
#include <queue>
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

class Solution {
    public:
      bool checkCompleteness(Node* root) {
          queue<Node*> q;
          q.push(root);
          bool nullFound = false;
  
          while(!q.empty() ) {
              Node* front = q.front();
              q.pop();
  
              if(front == NULL) {
                  nullFound = true;
              }
              else {
                  //front ek valid node h 
                  if(nullFound == true) {
                      //not a cbt
                      return false;
                  }
                  else {
                      //may be a cbt, continue processing
                      q.push(front->left);
                      q.push(front->right);
                  }
              }
          }
          return true;
      }
      bool checkMaxProperty(Node* root) {
          if(root == NULL) {
              return true;
          }
          if(root->left ==NULL && root->right == NULL) {
              return true;
          }
          
          bool leftAns = checkMaxProperty(root->left);
          bool rightAns = checkMaxProperty(root->right);
          
          
          bool option1 = true;
          if(root->left && root->data < root->left->data) {
              option1 = false;
          }
          bool option2 = true;
          if(root->right && root->data < root->right->data) {
              option2 = false;
          }
          
          bool currAns = option1 && option2;
          
          if(currAns && leftAns && rightAns)
              return true;
          else
              return false;
          
      }
      bool isHeap(struct Node* tree) {
          bool completeness = checkCompleteness(tree);
          bool maxProperty = checkMaxProperty(tree);
          if(completeness && maxProperty) {
              return true;
          }
          else {
              return false;
          }
      }
};
  
int main()
{
    // Construct the binary tree [97, 46, 37, 12, 3, 7, 31, 6, 9]
    Node* root = new Node(97);
    root->left = new Node(46);
    root->right = new Node(37);
    root->left->left = new Node(12);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(31);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(9);

    Solution sol;
    bool result = sol.isHeap(root);

    cout << (result ? "true" : "false") << endl;

    return 0;
}