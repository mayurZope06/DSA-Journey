#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
        void linkDelete(struct Node* head, int M, int N)
        {
            if (!head) // (head == NULL)
                return;
            
            Node* it = head;
            for(int i = 0; i < M - 1; ++i)
            {
                //if M nodes are not available
                if(!it)
                    return;

                it = it -> next;
            }

            //it -> would be at Mth node
            if(!it)
                return;
            
            Node* MthNode = it;
            it = MthNode -> next;

            for(int i =0; i < N; ++i)
            {
                if (!it)
                    break;
                Node* temp = it -> next;
                delete it;
                it = temp;
            }
            MthNode -> next = it;
            linkDelete(it, M, N);
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
  
    Node* head = new Node(9);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(10);

    cout << "Original List: ";
    printList(head);

    
    Solution solution;
    int M = 2, N = 1;
    solution.linkDelete(head, M, N);
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