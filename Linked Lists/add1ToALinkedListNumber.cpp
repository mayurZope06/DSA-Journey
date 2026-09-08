#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
        Node* reverseList(Node* &head)
        {
            Node* prev = NULL;
            Node* curr = head;

            while(curr != NULL)
            {
                Node* forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }
        Node* addOne(Node* head)
        {
            //step 1 : reverse list
            head = reverseList(head);

            //step 2 : add one
            //mujhe plus one krna hai , toh main carry ko hi 1 maan leta hu
            int carry = 1;
            Node* temp = head;

            while(temp != NULL)
            {
                int sum = carry + temp -> data;
                //current node me 1 hi digit store hoga double digit nahi ho skta
                int digit = sum % 10;
                carry = sum / 10;

                temp -> data = digit;

                //move to next node

                //special case jo last node k liye hoga
                if(temp -> next == NULL && carry != 0)
                {
                    Node* newNode = new Node(carry);
                    newNode -> next = NULL;
                    temp -> next = newNode;
                    temp = newNode;
                }
                //traverse krre h, toh aage toh badhna hi h
                temp = temp -> next;
            }
            //Step 3 : reverse list
            head = reverseList(head);
            return head;
        }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 1->2->2->1->2->0->2->2
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    Solution solution;
    head = solution.addOne(head);

    cout << "List Adding One: ";
    printList(head);

    // Clean up memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}