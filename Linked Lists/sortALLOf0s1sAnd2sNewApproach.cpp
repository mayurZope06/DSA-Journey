#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
        Node* segregate(Node* head)
        {
            //three marker nodes
            Node* zeroHead = new Node(-1);
            Node* zeroTail = zeroHead;

            Node* oneHead = new Node(-1);
            Node* oneTail = oneHead;

            Node* twoHead = new Node(-1);
            Node* twoTail = twoHead;

            //make three separate nodes
            Node* temp = head;
            while(temp)
            {
                if(temp -> data == 0)
                {
                    zeroTail -> next = temp;
                    zeroTail = zeroTail -> next;
                }
                else if(temp -> data == 1)
                {
                    oneTail -> next = temp;
                    oneTail = oneTail -> next;
                }
                else if(temp -> data == 2)
                {
                    twoTail -> next = temp;
                    twoTail = twoTail -> next;
                }
                temp = temp -> next;
            }
            //combine the three lists
            if(oneHead -> next) // != NULL
            {
                //original list me ek 1 node to pakka hogi hi
                zeroTail -> next = oneHead -> next;
            }
            else
            {
                zeroTail -> next = twoHead -> next;
            }
            oneTail -> next = twoHead -> next;
            twoTail -> next = nullptr;

            //Get the new head of the sorted list
            head = zeroHead -> next;

            //Free the dummy nodes
            delete zeroHead;
            delete oneHead;
            delete twoHead;

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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(2);

    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    Solution solution;
    head = solution.segregate(head);

    cout << "List after sorting 0s, 1s and 2s: ";
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