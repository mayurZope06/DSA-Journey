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
        void insertAtTail(Node* &toMove, Node* &head, Node* &tail)
        {
            //LL is empty
            if(head == NULL && tail == NULL)
            {
                head = toMove;
                tail = toMove;
            }
            else
            {
                tail -> next = toMove;
                tail = toMove;
            }
        }
        //Function to sort a Linked List of 0s, 1s and 2s
        Node* segregate(Node* head)
        {
            Node* zeroHead = NULL;
            Node* zeroTail = NULL;

            Node* oneHead = NULL;
            Node* oneTail = NULL;

            Node* twoHead = NULL;
            Node* twoTail = NULL;

            //LL pr traverse krenge and ye 3 LL ready krenge separate
            Node* temp = head;
            while(temp != NULL)
            {
                //create toMove node and isolate it
                Node* toMove = temp;
                temp = temp -> next;
                toMove -> next = NULL;

                if(toMove -> data == 0)
                {
                    insertAtTail(toMove, zeroHead, zeroTail);
                }
                else if(toMove -> data == 1)
                {
                    insertAtTail(toMove, oneHead, oneTail);
                }
                else if(toMove -> data == 2)
                {
                    insertAtTail(toMove, twoHead, twoTail);
                }
            }
            //yaha jab pohoche, toh teeno LL ready h 
            //merge them
            //empty wali possibility bhulna maat
            if(zeroHead != NULL)
            {
                //zeroList is non-empty
                if(oneHead != NULL)
                {
                    //one List is non-empty
                    zeroTail -> next = oneHead;
                    //merge with 2 wali List
                    oneTail -> next = twoHead;
                }
                else
                {
                    //one list is empty
                    zeroTail -> next = twoHead;
                }
                return zeroHead;
            }
            else
            {
                //zero List is empty
                if(oneHead != NULL)
                {
                    oneTail -> next = twoHead;
                    return oneHead;
                }
                else
                {
                    return twoHead;
                }
            }
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