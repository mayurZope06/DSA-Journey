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
        ListNode* reverseList(ListNode* &prev, ListNode* &curr)
        {
            //base case
            if(curr == NULL)
            {
                //iska mtlab LL reverse ho chuki hai 
                //reversed LL k starting node pr prev
                //wala pointer hai
                return prev;
            }
            //1 case hum solve karenge
            ListNode* forward = curr -> next;
            //current node ko piche ki disha me point karwaya
            curr -> next = prev;
            //pointers ko 1 step aage badhaya and recursion ko pakkda dia aage solve krne ke liye
            prev = curr;
            curr = forward;
            //baaki recursion sambhal lega
            return reverseList(prev, curr);
        }
        ListNode* reverseList(ListNode* head)
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* newHead = reverseList(prev, curr);
            return newHead;
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