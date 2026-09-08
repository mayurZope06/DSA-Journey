#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};

class Solution {
    public:
      void solve(Node* root, Node*& head, Node*& tail) {
          if(root == NULL) {
              return ;
          }
          
          //LNR - inorder
          solve(root->left, head, tail);
          //assume krke chalra hu, k left me LL bangyi h 
          //root node ko left LL se connect krna hoga 
          //head and tail ko update krna hoga 
          if(tail != NULL) {
              //ab tk ki LL empty nahi h 
              tail->right = root;
              root->left = tail;
              //tail update
              tail = root;
          }
          else {
              ///ab tk ki LL empty h, yaani first node 
              //ab insert hogi
              head = root;
              tail = root;
          }
          //ab mujhe right part ko connect krna h 
          solve(root->right, head, tail);
      }
      Node* bToDLL(Node* root) {
          Node* head = NULL;
          Node* tail = NULL;
          solve(root, head, tail);
          return head;
      }
  };

// Function to manually create a BST
Node* createTestTree() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    return root;
}

// Function to print Doubly Linked List
void printDLL(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    Node* root = createTestTree();

    Solution sol;
    Node* head = sol.bToDLL(root);

    printDLL(head);

    return 0;
}

// // R N L
// class Solution {
//     public:
//       void solve(Node* root, Node*& head) {
//           if(root == NULL) {
//               return;
//           }
//           //RNL
//           //R
//           solve(root->right, head);
//           //assume kr skte hu, k right part ki llbangyi hogi
//           //and head right part ki ll k start node pr hoga 
//           //N
//           root->right = head;
//           if(head != NULL) {
//               head->left = root;
//           }
//           //yaha tk aapki N and Rn ki LL ban chuki h 
//           //head ko update karna h 
//           head = root;
//           //ab Tree ka left part pending h 
//           //L
//           solve(root->left, head);
//       }
//       Node* bToDLL(Node* root) {
//           Node* head = NULL;
//           solve(root,head);
//           return head;
          
          
//       }
//   };