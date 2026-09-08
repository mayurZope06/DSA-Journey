#include <iostream>
#include <map>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        //constructor
        Node (int value)
        {
            this -> data = value;
            this -> next = NULL;
        }
};

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    map<int, Node*> map;
    Node* curr = head1;

    //L1 hashed
    while(curr)
    {
        map[curr -> data] = curr;
        curr = curr -> next;
    }

    curr = head2;

    //L2 hashed
    while(curr)
    {
        map[curr -> data] = curr;
        curr = curr -> next;
    }

    Node* UL = NULL;
    curr = 0;

    //iterate MAP & make final UL
    for(auto it = map.begin(); it != map.end(); it++)
    {
        if(!UL)
        {
            UL = it -> second;
            curr = UL;
        }
        else
        {
            curr -> next = it -> second;
            curr = curr -> next;
        }
    }
    curr -> next = 0;
    return UL;
}

// Function to print the linked list
void printList(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // List 1: 9 -> 6 -> 4 -> 2 -> 3 -> 8
    Node* l1 = new Node(9);
    l1->next = new Node(6);
    l1->next->next = new Node(4);
    l1->next->next->next = new Node(2);
    l1->next->next->next->next = new Node(3);
    l1->next->next->next->next->next = new Node(8);

    // List 2: 1 -> 2 -> 8 -> 6 -> 2
    Node* l2 = new Node(1);
    l2->next = new Node(2);
    l2->next->next = new Node(8);
    l2->next->next->next = new Node(6);
    l2->next->next->next->next = new Node(2);

    Node* unionList = makeUnion(l1, l2);

    cout << "Union of linked lists: ";
    printList(unionList);

    return 0;
}