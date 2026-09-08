#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

void fun (ListNode* head, int &positionAtTail, int &ans)
{
    if(head == 0 /*NULL*/)
        return;
    
    fun(head -> next, positionAtTail, ans);

    if(positionAtTail == 0)
        ans = head -> data;

    positionAtTail--;
}
int getNode (ListNode* head, int positionAtTail)
{
    int ans = -1;
    fun(head, positionAtTail, ans);
    return ans;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
  
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);

    cout << "Original List: ";
    printList(head);

    int positionFromTail = 2;
    int result = getNode(head, positionFromTail);
    cout << result;

    // Clean up memory
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}