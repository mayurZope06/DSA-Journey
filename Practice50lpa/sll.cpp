#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            this -> data = value;
            this-> next = NULL; 
        }
};


Node* insertAtHead(int value, Node* &head, Node* &tail) {
    if(head == NULL && tail == NULL) {
        Node* newNode = new Node(value);

        head = newNode;

        tail = newNode;
    }
    else {
        Node* newNode = new Node(value);

        newNode -> next = head;

        head = newNode;
    }
    return head;
}

Node* insertAtTail(int value, Node* &head, Node* &tail) {
    if(head == NULL && tail == NULL) {
        Node* newNode = new Node(value);

        head = newNode;

        tail = newNode;
    }
    else {
        Node* newNode = new Node(value);

        tail -> next = newNode;

        tail = newNode;
    }
    return head;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp -> next;
        len++;
    }
    return len;
}

Node* insertAtPosition(int position, int value, Node* &head, Node* &tail) {
    if(position == 1) {
        head = insertAtHead(value, head, tail);
    }
    else if(position == getLength(head) + 1) {
        head= insertAtTail(value, head, tail);
    }
    else {
        Node* temp = head;
        for(int i = 0; i < position - 2; i++) {
            temp = temp -> next;
        }
        Node* newNode = new Node(value);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void print (Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next; 
    } cout << "NULL" <<endl;
}

bool searchLL(int t, Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        if(temp -> data == t) {
            return true;
        }
        temp = temp -> next;
    }
    return false;
    
}


void deleteNodeFromLL (int position, Node* &head, Node* &tail) {
    if(head == NULL && tail == NULL) {
        cout << "No node to delete" << endl;
    }
    if(head == tail) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else {
        if(position == 1) {
            Node* temp = head;
            head = temp -> next;
            temp -> next = NULL;
            delete temp;
        }
        else {
            Node* prev = head;
            for(int i = 0; i < position - 2; i++) {
                prev = prev -> next;
            }
            Node* curr = prev -> next;
            Node* forward = curr -> next;
            prev -> next = forward;
            curr -> next = NULL;
            delete curr;
        }
    }
}

int main()
{   
    // Node* first = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    insertAtPosition(1, 10, head, tail);
    insertAtPosition(2, 20, head, tail);
    insertAtPosition(2, 30, head, tail);
    insertAtPosition(1, 730, head, tail);
    print(head);

    // cout << searchLL(210, head);

    deleteNodeFromLL(3, head, tail);
    print(head);

    return 0;
}