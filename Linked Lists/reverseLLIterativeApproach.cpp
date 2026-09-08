#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        ListNode* reverseList(ListNode* head)
        {
            //iterative approach
            ListNode* prev = NULL;
            ListNode* curr = head;

            while(curr != NULL)
            {
                ListNode* forward = curr -> next;
                //forward pointer set hogya ab aage ki list lost nhi hogi
                curr -> next = prev;
                prev = curr;
                curr = forward;
            }
            //new head of linked list kon hoga -> pre pointer
            return prev;
        }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Solution s1;

    // Create a linked list
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createLinkedList(arr, size);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse
    ListNode* reverse = s1.reverseList(head);

    // Print the value of the reversed list
    cout << "Reverse: ";
    printLinkedList(reverse);
    return 0;
}