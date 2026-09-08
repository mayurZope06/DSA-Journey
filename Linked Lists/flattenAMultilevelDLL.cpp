#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    // Constructor to initialize a node
    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution
{
    public:
        Node* solve(Node* head)
        {
            auto it = head;
            auto tail = it; // fortracking tail node

            while(it)
            {
                if(it -> child)
                {
                    auto childTail = solve(it -> child); // tail node

                    //flatten ka kaam
                    auto temp = it -> next;
                    it -> next = it -> child;
                    it -> next -> prev = it;
                    childTail -> next = temp;

                    if(temp)
                        temp -> prev = childTail;
                    it -> child = nullptr;
                }
                tail = it;
                it = it -> next;
            }
            return tail;
        }
        Node* flatten (Node* head)
        {
            if(!head)
                return nullptr;
            
            solve(head);
            return head;
        }
};

// Utility function to print a flattened list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    // Creating a multilevel doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Adding a child to the second node
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;
    head->next->child->next->next = new Node(6);
    head->next->child->next->next->prev = head->next->child->next;

    // Print the original list structure
    cout << "Original list structure:" << endl;
    cout << "Level 1: 1 <-> 2 <-> 3" << endl;
    cout << "Child of 2: 4 <-> 5 <-> 6" << endl;

    Solution s;
    Node* flattened = s.flatten(head);

    // Print the flattened list
    cout << "\nFlattened list:" << endl;
    printList(flattened);

    return 0;
}
