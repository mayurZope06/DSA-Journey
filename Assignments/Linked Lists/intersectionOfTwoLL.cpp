#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Solution
{
    public:
        Node* findIntersection(Node* head1, Node* head2)
        {
            unordered_map<int ,int> map;
            Node* curr = head2;

            //hash L2 items
            while(curr)
            {
                map[curr -> data]++;
                curr = curr -> next;
            }
            Node* IL = NULL;
            Node* it = 0;
            curr = head1;

            while(curr)
            {
                if(map.find(curr -> data) != map.end())
                {
                    //node val found in L2
                    if(!IL)
                    {
                        IL = curr;
                        it = IL;
                    }
                    else
                    {
                        if(map[curr -> data] > 0)
                        {
                            it -> next = curr;
                            it = it -> next;
                            map[curr -> data]--;
                        }
                    }
                }
                curr = curr -> next;
            }
            it -> next = NULL;
            return IL;
        }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
   
    Node* head1 = new Node(7);
    head1->next = new Node(6);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(3);
    head1->next->next->next->next->next = new Node(8);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(6);

    // Print the original list structure
    cout << "Original list structure:" << endl;
    printList(head1);
    printList(head2);

    Solution s;
    Node* result = s.findIntersection(head1, head2);

    printList(result);


    return 0;
}
