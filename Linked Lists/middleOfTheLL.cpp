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
        ListNode* middleNode(ListNode* head)
        {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != NULL)
            {
                //fast ko ek step aage karo
                fast = fast -> next;
                //NULL check karo and fast ko ek step aur aage kro
                if(fast != NULL)
                {
                    fast = fast -> next;
                    //ab fast k 2 steps complete ho chuke hai toh ab slow ko bhi ek step aage karo
                    slow = slow -> next;
                }
            }
            return slow;
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


int main() {
    Solution solution;

    // Create a linked list
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createLinkedList(arr, size);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Find the middle node
    ListNode* middle = solution.middleNode(head);

    // Print the value of the middle node
    if (middle != nullptr) {
        cout << "Middle Node Value: " << middle->val << endl;
    } else {
        cout << "The list is empty." << endl;
    }
    printLinkedList(middle);

    return 0;
}
